//
// Created by lilu on 05.12.2021.
//

#ifndef GAME_EVENTMANAGER_H
#define GAME_EVENTMANAGER_H
#define GLEW_NO_GLU
#include "SDL.h"
#include <stdlib.h>
#include <string>


/*struct KeyEvent : public BaseEvent
{
    KeyCode key = KeyCode::UNKNOWN;

    enum class Type
    {
        KeyDown,
        KeyUp,
    } type;

    KeyEvent(Type type, KeyCode key) : type(type), key(key) { }
};
*/
class EventManager
{
public:
    SDL_Event event;
    bool KEYS[322];  // 322 is the number of SDLK_DOWN events


    EventManager();

    void keyboard();

    void handleInput();
};


#endif //GAME_EVENTMANAGER_H
