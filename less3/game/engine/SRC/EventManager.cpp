//
// Created by lilu on 05.12.2021.
//

#include "EventManager.h"
#include "SDL.h"



EventManager::EventManager()
{
    for(int i = 0; i < 322; i++) { // init them all to false
        KEYS[i] = false;
    }
}

void EventManager:: keyboard() {
    // message processing loop

    while (SDL_PollEvent(&event)) {
        // check for messages
        switch (event.type) {
            // exit if the window is closed
            case SDL_QUIT:
                printf("QUIT"); // set game state to done,(do what you want here)
                break;
                // check for keypresses
            case SDL_KEYDOWN:
                KEYS[event.key.keysym.sym] = true;
                break;
            case SDL_KEYUP:
                KEYS[event.key.keysym.sym] = false;
                break;
            default:
                break;
        }
    } // end of message processing
}

void EventManager:: handleInput() {
    if(KEYS[SDLK_LEFT]) { // move left
        printf("\n LEFT \n");
    }
    if(KEYS[SDLK_RIGHT]) { // move right
        printf("\n RIGHT \n");
    }
    if(KEYS[SDLK_a]) { // shoot
        printf("\n AA \n");
    }
    if(KEYS[SDLK_d]) {
        printf("\n DDD \n");
    }
    if(KEYS[SDLK_SPACE]) {
        printf("\n SPACE \n");
    }

    if(KEYS[SDLK_ESCAPE]) {
        printf("\n QUITE \n");
    }
}