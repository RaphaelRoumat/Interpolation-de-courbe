#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <chrono>
#include "RenderWindow.hpp"
#include "Logic.hpp"



int main(int argc, char *args[])
{
    /* Iniatilisation de SDL */
    if (SDL_Init(SDL_INIT_VIDEO))
        std::cout << "SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

    Logic logic(800, 500);
    RenderWindow window("Curve interpolation", 800, 500, &logic);

    

    bool running = true;
    SDL_Event event;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT :
                    running = false;
                    break;
                
                case SDL_MOUSEBUTTONDOWN:
                    int x, y;
                    SDL_GetMouseState(&x, &y);
                    logic.addPoint(x,y);
                    break;

                case SDL_KEYDOWN:
                    logic.printPoints();
                    break;

                default:
                    break;

            }
            
        }
        window.clear();
        window.render();
        window.display();
        
    }

    window.CleanUp();
    IMG_Quit();
    SDL_Quit();

    return 0;
}
