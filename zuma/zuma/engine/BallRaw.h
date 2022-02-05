//
// Created by lilu on 01/02/2022.
//

#ifndef ZUMA_BALLRAW_H
#define ZUMA_BALLRAW_H

#include <vector>
#include <memory>
#include <glm/vec2.hpp>
#include "LevelBall.h"

class Engine;

class BallRaw
{
public:
    BallRaw(Engine *_engine,  int size);
    Engine *_engine;
    std::vector<std::shared_ptr<LevelBall>> _raw;
    int _initialSize;
    int _currentSize = 1;
    float _delta;
    std::vector<int> colorBall;
    int j =0;
    int k = 0;
    std::vector<glm::vec2> _points;
    glm::vec2 _initialPoint = glm::vec2(550, 500);
    glm::vec2 _finalPoint = glm::vec2(400, 450);
    void update();
};


#endif //ZUMA_BALLRAW_H
