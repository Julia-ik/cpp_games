//
// Created by lilu on 16/01/2022.
//

#ifndef ZUMA_EVENTMANAGER_H
#define ZUMA_EVENTMANAGER_H


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

#endif //ZUMA_EVENTMANAGER_H
