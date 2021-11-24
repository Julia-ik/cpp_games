#ifndef ENGINE_LIBRARY_H
#define ENGINE_LIBRARY_H
#include <string_view>
#include <SDL.h>
#include "vector"
#include "../../Model.h"

class Engine
{

public:
    SDL_Window *window;
    SDL_Renderer *r;
    int width;
    int heights;
    SDL_bool done = SDL_FALSE;

    Engine(int w, int h);
    void flip(SDL_Renderer **r);

    void init(std::string_view name, SDL_Window **window, SDL_Renderer **r);
    void full(Model * model);
    void drawTriangle(SDL_Renderer **r, float x1, float y1, float x2, float y2, float x3, float y3);
    void destroyEngine(SDL_Window **window, SDL_Renderer **renderer);

};
#endif //ENGINE_LIBRARY_H
