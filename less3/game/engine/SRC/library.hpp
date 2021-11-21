#ifndef ENGINE_LIBRARY_H
#define ENGINE_LIBRARY_H
#include <string_view>
#include <SDL.h>
#include "vector"

class Engine
{

public:
    void init(std::string_view name);
    void draw();

    int x=0;
    int y=0;
    int z=0;
    void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3);
    //SDL_Color white = {255, 255, 255};
    //SDL_Color red = {255, 0 ,0};
    SDL_Window * window;
    SDL_Renderer *r;
    //SDL_SetRenderDrawColor(255,0,0,255);
   // Pimpl *_pimpl;


};
#endif //ENGINE_LIBRARY_H
