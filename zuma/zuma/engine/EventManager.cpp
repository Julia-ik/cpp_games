//
// Created by lilu on 16/01/2022.
//

#include "EventManager.h"

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