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
    Engine *_engine;
    float _speed=0.0;
    float _turnSpeed=0.0;
    bool isLeft = false;
    bool isRight = false;

    std::vector<int> colorBall;
    std::shared_ptr<Ball> nextBall;
    int i = 0;

    Frog(Engine *engine, glm::vec2 position, glm::vec2 size, float rotation,
         glm::vec2 center);

    void registerEventHandler();
    void moveLeft(std::shared_ptr<Node>, float delta);
    void moveRight(std::shared_ptr<Node> sprite, float delta);
    void updateSelf(float delta) override;

private:
    bool _couldShooting;
    void generateBallBanch();


};
#endif //ZUMA_FROG_H
