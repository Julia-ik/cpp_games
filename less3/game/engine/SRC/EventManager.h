//
// Created by lilu on 05.12.2021.
//

#ifndef GAME_EVENTMANAGER_H
#define GAME_EVENTMANAGER_H
#define GLEW_NO_GLU
#include "SDL.h"
#include <stdlib.h>
#include <string>
#include "Node.h"
#include "Sound.h"
#include "Tank.h"
#include "library.hpp"
#include "Button.h"


class EventManager
{
public:
    SDL_Event event;
    Engine *_engine;
    Tank *_tank;
    Button *_button;


    EventManager(Engine *engine, Tank *tank, Button *button);

    void RegisterEvents();

private:
    int _currentMouseX;
    int _currentMouseY;
};


#endif //GAME_EVENTMANAGER_H
