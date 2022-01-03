//
// Created by lilu on 13/12/2021.
//

#ifndef GAME_BUTTON_H
#define GAME_BUTTON_H
#include "Node.h"
#include "Shader.h"
#include "Sprite.h"
#include "library.hpp"
#include <memory>
#include <SDL.h>



class Button: public Node
{
public:

    Shader shader;
    bool isPressed = false;
    Node node;
    Engine *_engine;

    Button(Engine *engine, const Shader &shader, glm::vec2 position, glm::vec2 size,
           float rotation, glm::vec2 center);

    void registerEventHandler();
};


#endif //GAME_BUTTON_H
