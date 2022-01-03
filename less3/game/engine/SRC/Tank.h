//
// Created by lilu on 11/12/2021.
//

#ifndef GAME_TANK_H
#define GAME_TANK_H


#include "Node.h"
#include "Shader.h"
#include "Sprite.h"
#include <glm/gtx/rotate_vector.hpp>
#include "library.hpp"


class Tank : public Node
{
public:
    Shader shader;
    Engine *_engine;

    std::vector<std::shared_ptr<Sound>> _sounds;

    float _speed=0.0;
    float _turnSpeed=0.0;
    bool isLeft = false;
    bool isRight = false;
    bool isShooting = false;
    bool isMovingForward = false;
    bool isMovingBack = false;
    bool isGunLeft = false;
    bool isGunRigft = false;

    Tank(Engine *engine,const Shader &shader, glm::vec2 position, glm::vec2 size,
         float rotation, glm::vec2 center);

    void registerEventHandler();

  //  Sound createSound {return /*массив вик птр*/};

    void moveLeft(std::shared_ptr<Node>, float delta);

    void moveRight(std::shared_ptr<Node> sprite, float delta);

    void move(std::shared_ptr<Node> sprite, float delta);

    void moveBack(std::shared_ptr<Node> sprite, float delta);
    void updateSelf(float delta) override;

    template<typename T, typename... Args>
    std::shared_ptr<T> createShared(Args&&... args) const
    {
        if constexpr(std::is_constructible_v<T, const Tank&, Args&&...>)
        {
            return std::make_shared<T>(*this, std::forward<Args>(args)...);
        }
        else
        {
            return std::make_shared<T>(std::forward<Args>(args)...);
        }
    }

    void init();


    void shoot(std::shared_ptr<Node> sprite, float delta);
};


#endif //GAME_TANK_H
