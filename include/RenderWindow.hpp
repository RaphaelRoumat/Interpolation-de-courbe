#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Logic.hpp"

class RenderWindow
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    Logic* logic;
    int width, height;


public:
    RenderWindow(const char *title, int width, int height, Logic* logic);
    SDL_Texture *loadTexture(const char *file_path);
    void clear();
    void render();
    void display();
    void CleanUp();
    void renderPoints();
    void renderCurve();
};
