#include "library.hpp"
#include "../../Model.h"

#include <memory>
#include <SDL.h>
#include <fstream>


Engine::Engine(int w, int h)
{
    width=w;
    heights=h;
    window = SDL_CreateWindow("  ",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width, heights, 0);
    r = SDL_CreateRenderer(window, -1, 0);
}
void Engine::init(std::string_view name,SDL_Window **window, SDL_Renderer **r)
{
    SDL_version version = {0, 0, 0};
    SDL_GetVersion(&version);
    printf("SDL Version: %d.%d.%d, version.major, version.patch, version minor");


    SDL_Init(SDL_INIT_VIDEO);
}

void Engine::drawTriangle(SDL_Renderer **r, float x1, float y1, float x2, float y2, float x3, float y3)
{
    SDL_SetRenderDrawColor(*r, 255, 0, 0, SDL_ALPHA_OPAQUE);

    SDL_RenderDrawLine(*r,x1, y1, x2, y2);
    SDL_RenderDrawLine(*r,x1,y1,x3,y3);
    SDL_RenderDrawLine(*r, x2,y2,x3,y3);
    SDL_RenderPresent(*r);
}

void Engine::full(Model * model)
{

    for(int i=0; i<model->fvector.size();i++)
    {
        int x01 = model->vvector[model->fvector[i]->first]-> x;
        int y01 = model->vvector[model->fvector[i]->first]-> y;
        int x02 = model->vvector[model->fvector[i]->second]->x;
        int y02 = model->vvector[model->fvector[i]->second]->y;
        int x03 = model->vvector[model->fvector[i]->third]-> x;
        int y03 = model->vvector[model->fvector[i]->third]-> y;

        drawTriangle(&r,x01,y01,x02,y02,x03,y03);
    }

    destroyEngine(&window,&r);
}

void Engine::destroyEngine(SDL_Window **window, SDL_Renderer **renderer)
{
    SDL_Delay(7000);
    SDL_DestroyWindow(*window);
    SDL_Quit();
}
