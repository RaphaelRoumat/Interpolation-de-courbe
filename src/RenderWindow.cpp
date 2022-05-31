#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "SDL2_framerate.h"
#include "SDL2_gfxPrimitives.h"
#include "SDL2_gfxPrimitives_font.h"
#include "SDL2_imageFilter.h"
#include "SDL2_rotozoom.h"

#include "RenderWindow.hpp"
#include "Logic.hpp"

RenderWindow::RenderWindow(const char *title, int width, int height, Logic* logic)
    : window(NULL), renderer(NULL), logic(logic), width(width), height(height)
{
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);

    if (!window)
        std::cout << "SDL_CreateWindow HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!renderer)
        std::cout << "SDL_CreateRenderer HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;
}

SDL_Texture *RenderWindow::loadTexture(const char *file_path)
{
    SDL_Texture *texture = NULL;
    texture = IMG_LoadTexture(renderer, file_path);
    if (!texture)
        std::cout << "IMG_LoadTexture HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

    return texture;
}

void RenderWindow::clear()
{
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderClear(renderer);
}


void RenderWindow::render()
{
    renderCurve();

    renderPoints();

}

void RenderWindow::renderPoints()
{
    ListePoint points = logic->getPoints();

    for(std::size_t i = 0; i < points.size(); i++)
    {
        int x , y;
        x = points[i].getX(); y = points[i].getY();
        lineRGBA(renderer, x - 5, y - 5, x + 5, y + 5, 0, 255, 0, 255 );
        lineRGBA(renderer, x - 5, y + 5, x + 5, y - 5, 0, 255, 0, 255 );
    }
}

void RenderWindow::renderCurve()
{
    int previous;
    int current;
    for(int x = 0; x < width; x++)
    {
        if(x != 0)
        {
            current = logic->getCurvePixel_y(x);
            aalineRGBA(renderer, x - 1 , previous ,x, current, 0, 0, 255, 255);
            previous = current;
        }
        else
        {
            current = logic->getCurvePixel_y(x);
            pixelRGBA(renderer, x, logic->getCurvePixel_y(x), 0, 0, 255, 255);
            previous = current;
        }
    }
}



void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}

void RenderWindow::CleanUp()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}