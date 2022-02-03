//
// Created by lilu on 01/02/2022.
//

#include "BallRaw.h"
#include "LevelBall.h"
#include "Engine.h"

BallRaw::BallRaw(Engine *engine,  int size): _engine(engine)
{
    _initialSize = 15;
    _points.emplace_back(_initialPoint);
    _points.emplace_back(glm::vec2(100, 100));
    _points.emplace_back(glm::vec2(100, 350));
    _points.emplace_back(glm::vec2(350, 350));
    _points.emplace_back(glm::vec2(350, 200));
    _points.emplace_back(_finalPoint);

}

void BallRaw::update()
{
    if(_raw.size() == 0)
    {
        auto ball = _engine->createShared<LevelBall>(glm::vec2(500.0, 600.0),
                                                     glm::vec2(3.0f, 3.0f), 0.0f, 500.0f,
                                                     std::make_shared<BallRaw>(*this));
        ball->_tempPoint = _initialPoint;
        _engine->scene.addNode(ball, 4);
        _raw.emplace_back(ball);
    }

    if(_currentSize<_initialSize && (
            abs(_raw[_raw.size()-1]->getPosition().x - 500) > 50.0f ||
            abs(_raw[_raw.size()-1]->getPosition().y - 600) > 50.0f))
    {
        auto ball = _engine->createShared<LevelBall>(glm::vec2(500.0, 600.0),
                                                     glm::vec2(3.0f, 3.0f), 0.0f, 500.0f,
                                                     std::make_shared<BallRaw>(*this));
        ball->_tempPoint = _initialPoint;
        _engine->scene.addNode(ball, 4);

        _raw.emplace_back(ball);
        _currentSize ++;
    }



}