//
// Created by lilu on 05.12.2021.
//

#include "EventManager.h"
#include "SDL.h"
#include <memory>


EventManager::EventManager(Engine *engine, Tank *tank, Button *button): _engine(engine), _tank(tank), _button(button)
{
    RegisterEvents();
}

void EventManager::RegisterEvents()
{
    while(SDL_PollEvent(&event)) {


        if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            if (event.motion.x >=_button->_position.x &&
                event.motion.x <=_button->_position.x + _button->_contentSize.x &&
                event.motion.y >= _button->_position.y &&
                event.motion.y <= _button->_position.y + _button->_contentSize.y)
            {
                _button->isPressed = true;
                printf("\n ORDER %d\n",_button->_nodes[0]->_zOrder);
                _button->_nodes[0]->_contentSize.x*=0.8f;
                _button->_nodes[0]->_contentSize.y*=0.8f;
            }
        }
       if(event.type == SDL_MOUSEBUTTONUP && _button->isPressed)
        {
                _button->_nodes[0]->_contentSize.x/=0.8f;
                _button->_nodes[0]->_contentSize.y/=0.8f;
                _button->isPressed = false;
        }

        auto keyState = SDL_GetKeyboardState(NULL);

        if (keyState[SDL_SCANCODE_A]) {
            _tank->_nodes[1]->isLeft = true;
        }
        if (!keyState[SDL_SCANCODE_A]) {
            _tank->_nodes[1]->isLeft = false;
        }
        if (keyState[SDL_SCANCODE_D]) {
            _tank->_nodes[1]->isRight=true;
        }
        if (!keyState[SDL_SCANCODE_D]) {
            _tank->_nodes[1]->isRight= false;
        }
        if (keyState[SDL_SCANCODE_LEFT]) {
            //_spriteRenderers["body"]->_isLeft=true;
            _tank->_nodes[0]->isLeft=true;

        }
        if (!keyState[SDL_SCANCODE_LEFT]) {
            //_spriteRenderers["body"]->_isLeft=true;
            _tank->_nodes[0]->isLeft=false;

        }
        if (keyState[SDL_SCANCODE_RIGHT]) {
            _tank->_nodes[0]->isRight=true;
        }
        if (!keyState[SDL_SCANCODE_RIGHT]) {
            _tank->_nodes[0]->isRight=false;
        }
        if (keyState[SDL_SCANCODE_SPACE]) {

            _engine->scene.addNode(_tank->createShared<Sprite>(ResourceManager::GetShader("sprite"),
                                                        glm::vec2 (_tank->_nodes[1]->getPosition().x + 68,
                                                                   _tank->_nodes[1]->getPosition().y+8),
                                                        glm::vec2(10.0f, 10.0f),
                                                        0.0f, glm::vec2(0.5f),
                                                        glm::vec4(1.0f, 0.0f,0.0f,0.8f),"fire"), 7);

            _engine->_sounds[0]->pause();
            _tank->_sounds[1]->play();

        }
        if (!keyState[SDL_SCANCODE_SPACE]) {
            _tank->_sounds[1]->stop();
        }
        if (keyState[SDL_SCANCODE_ESCAPE]) {
            _engine->isActive = false;
        }
        if(keyState[SDL_SCANCODE_UP])
        {
            _engine->_sounds[0]->pause();
            _tank->_sounds[0]->play();

            _tank->_nodes[0]->isMovingForward = true;
        }
        if(!keyState[SDL_SCANCODE_UP])
        {
            _tank->_nodes[0]->isMovingForward = false;

        }
        if(keyState[SDL_SCANCODE_DOWN])
        {
            _engine->_sounds[0]->pause();
            _tank->_sounds[0]->play();

            _tank->_nodes[0]->isMovingBack = true;
        }
        if(!keyState[SDL_SCANCODE_DOWN])
        {
            _tank->_nodes[0]->isMovingBack = false;
        }
        if(!keyState[SDL_SCANCODE_DOWN] && !keyState[SDL_SCANCODE_UP]
           && !keyState[SDL_SCANCODE_SPACE])
        {
            _engine->_sounds[0]->play();
        }
        if(!keyState[SDL_SCANCODE_DOWN] && !keyState[SDL_SCANCODE_UP])
        {
            _tank->_sounds[0]->pause();
        }
        if(keyState[SDL_SCANCODE_KP_PLUS])
        {
            _tank->_sounds[0]->volumePlus();
        }
        if(keyState[SDL_SCANCODE_KP_MINUS])
        {
            _tank->_sounds[0]->volumeMinus();
        }

    }
}