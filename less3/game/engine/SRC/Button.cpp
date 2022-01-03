//
// Created by lilu on 13/12/2021.
//

#include "Button.h"
#include "library.hpp"


Button::Button(Engine *engine,const Shader &shader, glm::vec2 position,
               glm::vec2 size, float rotation, glm::vec2 center): _engine(engine)
{
    _position=position;
    _contentSize = size;
    _rotation = rotation;
    _anchor=center;


    auto button = _engine->createShared<Sprite>(shader, _position, _contentSize, _rotation, _anchor,
                                 glm::vec4(1.0f, 0.0f, 0.5, 1.0f),"button");



    addNode(button, 6);
    registerEventHandler();

}
void Button::registerEventHandler()
{
    _engine->_eventManager.addHandler(
            [this] (const SDL_Event& event) {
                if (event.type == SDL_MOUSEBUTTONDOWN) {
                    if (event.motion.x >= _position.x &&
                        event.motion.x <= _position.x + _contentSize.x*1000.0f &&
                        event.motion.y >= _position.y &&
                        event.motion.y <= _position.y + _contentSize.y*1000)
                    {
                        isPressed = true;
                        _nodes[0]->_contentSize.x *= 0.8f;
                        _nodes[0]->_contentSize.y *= 0.8f;
                    }
                }
                if (event.type == SDL_MOUSEBUTTONUP && isPressed) {
                    _nodes[0]->_contentSize.x /= 0.8f;
                    _nodes[0]->_contentSize.y /= 0.8f;
                    isPressed = false;
                }
            });


}