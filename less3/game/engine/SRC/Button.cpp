//
// Created by lilu on 13/12/2021.
//

#include "Button.h"


Button::Button(const Shader &shader, glm::vec2 position, glm::vec2 size, float rotation, glm::vec2 center)
{
    _position=position;
    _contentSize = size;
    _rotation = rotation;
    _anchor=center;

    auto button = createShared<Sprite>(shader, _position, _contentSize, _rotation, _anchor,
                                 glm::vec4(1.0f, 0.0f, 0.5, 1.0f),"button");



    addNode(button, 6);

}
