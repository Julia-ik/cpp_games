//
// Created by lilu on 16/01/2022.
//

#ifndef ZUMA_FROG_H
#define ZUMA_FROG_H
#include "Node.h"
#include "Shader.h"
#include "Sprite.h"
#include <glm/gtx/rotate_vector.hpp>
#include "Engine.h"


class Frog: public Node
{
public:
    Shader shader;
    Engine *_engine;
    float _speed=0.0;
    float _turnSpeed=0.0;
    bool isLeft = false;
    bool isRight = false;

    Frog(Engine *engine,const Shader &shader, glm::vec2 position, glm::vec2 size,
         float rotation, glm::vec2 center);

    void registerEventHandler();

    //TODO  Sound createSound {return /*массив вик птр*/};

    void moveLeft(std::shared_ptr<Node>, float delta);

    void moveRight(std::shared_ptr<Node> sprite, float delta);

    void updateSelf(float delta) override;


    void init();


    void shoot(std::shared_ptr<Node> sprite, float delta);

    template<typename T, typename... Args>
    std::shared_ptr<T> createShared(Args&&... args) const
    {
        if constexpr(std::is_constructible_v<T, const Frog&, Args&&...>)
        {
            return std::make_shared<T>(*this, std::forward<Args>(args)...);
        }
        else
        {
            return std::make_shared<T>(std::forward<Args>(args)...);
        }
    }

};
#endif //ZUMA_FROG_H
