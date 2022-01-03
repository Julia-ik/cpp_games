//
// Created by lilu on 05.12.2021.
//

#ifndef GAME_EVENTMANAGER_H
#define GAME_EVENTMANAGER_H
#define GLEW_NO_GLU
#include "SDL.h"
#include <stdlib.h>
#include <string>
#include <functional>

class EventManager
{
public:
    using EventHandler = std::function<void(const SDL_Event & event)>;
    void addHandler(EventHandler handler) const;
    void removeHandler(EventHandler handler);
    void eventHandler();
private:
    SDL_Event event;


   mutable std::vector<EventHandler> handlers;




};


#endif //GAME_EVENTMANAGER_H
