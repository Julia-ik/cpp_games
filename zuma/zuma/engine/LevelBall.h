//
// Created by lilu on 02/02/2022.
//

#ifndef ZUMA_LEVELBALL_H
#define ZUMA_LEVELBALL_H


#include "Ball.h"
#include <vector>

class BallRaw;

class LevelBall : public Ball
        {
public:
    LevelBall(const Engine& engine, glm::vec2 position, glm::vec2 size,
              float rotation, float speed, std::shared_ptr<BallRaw> raw);
    void updateSelf(float delta) override;
    int j =0;
    std::shared_ptr<BallRaw> _ballraw;


    glm::vec2 _tempPoint;
};


#endif //ZUMA_LEVELBALL_H
