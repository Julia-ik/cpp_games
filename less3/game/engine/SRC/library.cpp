#include "library.hpp"
#include <memory>
#include <SDL.h>
#include <fstream>

void Engine::init(std::string_view name)
{
    SDL_version version = {0, 0, 0};
    SDL_GetVersion(&version);
    printf("SDL Version: %d.%d.%d, version.major, version.patch, version minor");
}

void Engine::draw()
{



    //SDL_Init(SDL_INIT_EVERYTHING);
    //window = SDL_CreateWindow("name", 100, 100,680,480,0);

    //if (window == NULL)
    //{
     //   printf("\nCould not create window: %s\n", SDL_GetError());
    //}
    //SDL_Delay(3000);
    //SDL_DestroyWindow(window);
    //SDL_Quit();

    //SDL_SetRenderDrawColor(r,255,0,0,255);
    //SDL_RenderDrawLine(r, 300, 200,380,260);

    if (SDL_CreateWindowAndRenderer(640, 480, 0, &window, &r) == 0) {
        SDL_bool done = SDL_FALSE;

        while (!done) {
            SDL_Event event;

            SDL_SetRenderDrawColor(r, 0, 0, 0, SDL_ALPHA_OPAQUE);
            SDL_RenderClear(r);

            SDL_SetRenderDrawColor(r, 255, 0, 0, SDL_ALPHA_OPAQUE);
            SDL_RenderDrawLine(r,320, 480, 0, 0);
            SDL_RenderPresent(r);

            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    done = SDL_TRUE;
                }
            }
        }
    }

    if (r) {
        SDL_DestroyRenderer(r);

}}


void Engine::drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3)
{


    if (SDL_CreateWindowAndRenderer(640, 480, 0, &window, &r) == 0) {
        SDL_bool done = SDL_FALSE;

        while (!done) {
            SDL_Event event;

            SDL_SetRenderDrawColor(r, 0, 0, 0, SDL_ALPHA_OPAQUE);
            SDL_RenderClear(r);

            SDL_SetRenderDrawColor(r, 255, 0, 0, SDL_ALPHA_OPAQUE);

            SDL_RenderDrawLine(r,x1, y1, x2, y2);
            SDL_RenderDrawLine(r,x1,y1,x3,y3);
            SDL_RenderDrawLine(r, x2,y2,x3,y3);
            SDL_RenderPresent(r);

            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    done = SDL_TRUE;
                }
            }
        }
    }
}


//engine.init("Windows Name");
//while (engine.isActive())
//{
//engine.update();
//}

