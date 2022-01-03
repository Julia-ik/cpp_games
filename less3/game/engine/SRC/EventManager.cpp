//
// Created by lilu on 05.12.2021.
//

#include "EventManager.h"
#include "SDL.h"

void EventManager::eventHandler()
{
    while(SDL_PollEvent(&event))
    {
        for(int i =0; i<handlers.size(); i++){

            handlers[i](event);
        }
    }
}
void EventManager::addHandler(EventHandler handler) const
{
    handlers.emplace_back(handler);
}