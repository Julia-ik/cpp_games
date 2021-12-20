//
// Created by lilu on 13/12/2021.
//

#ifndef GAME_BUTTON_H
#define GAME_BUTTON_H
#include "Node.h"
#include "Shader.h"
#include "Sprite.h"
#include <memory>
#include <SDL.h>



class Button: public Node
{
public:

    Shader shader;
    bool isPressed = false;

    Button(const Shader &shader, glm::vec2 position, glm::vec2 size,
           float rotation, glm::vec2 center);

    template<typename T, typename... Args>
    std::shared_ptr<T> createShared(Args&&... args) const
    {
        if constexpr(std::is_constructible_v<T, const Button&, Args&&...>)
        {
            return std::make_shared<T>(*this, std::forward<Args>(args)...);
        }
        else
        {
            return std::make_shared<T>(std::forward<Args>(args)...);
        }
    }

};


#endif //GAME_BUTTON_H
