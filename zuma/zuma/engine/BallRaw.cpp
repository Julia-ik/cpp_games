//
// Created by lilu on 01/02/2022.
//

#include "BallRaw.h"
#include "LevelBall.h"
#include "Engine.h"

BallRaw::BallRaw(Engine *engine,  int size): _engine(engine)
{
    _initialSize = size;
    _points.emplace_back(_initialPoint);
    _points.emplace_back(glm::vec2(550, 90));
    _points.emplace_back(glm::vec2(100, 90));
    _points.emplace_back(glm::vec2(100, 510));
    _points.emplace_back(glm::vec2(490, 510));
    _points.emplace_back(glm::vec2(490, 140));
    _points.emplace_back(glm::vec2(160, 140));
    _points.emplace_back(glm::vec2(160, 450));
    _points.emplace_back(_finalPoint);

    colorBall = _engine->chooseColor(size);

}

void BallRaw::update()
{
    if(_raw.size() == 0)
    {
        auto ball = _engine->createShared<LevelBall>(_initialPoint,
                                                     glm::vec2(3.0f, 3.0f), 0.0f, 500.0f,
                                                     std::make_shared<BallRaw>(*this), colorBall[k]);
        k++;
        ball->_tempPoint = _initialPoint;
        _engine->scene.addNode(ball, 4);
        _raw.emplace_back(ball);
    }

    if(_currentSize<_initialSize && (
            abs(_raw[_raw.size()-1]->getPosition().x - _initialPoint.x) > 45.0f ||
            abs(_raw[_raw.size()-1]->getPosition().y - _initialPoint.y) > 45.0f))
    {
        auto ball = _engine->createShared<LevelBall>(_initialPoint,
                                                     glm::vec2(3.0f, 3.0f), 0.0f, 500.0f,
                                                     std::make_shared<BallRaw>(*this), colorBall[k]);
        k++;
        ball->_tempPoint = _initialPoint;
        _engine->scene.addNode(ball, 4);

        _raw.emplace_back(ball);
        _currentSize ++;
    }

    deleteMatch();
}

void BallRaw::deleteMatch()
{
    for(int i=0; i<_raw.size(); i++)
    {
       if(i>1 && _raw[i]->_colorIndex == _raw[i-1]->_colorIndex && _raw[i]->_colorIndex == _raw[i-2]->_colorIndex)
       {
           _engine->scene.removeNodeByInd(_raw[i]->refInd);
           _engine->scene.removeNodeByInd(_raw[i-1]->refInd);
           _engine->scene.removeNodeByInd(_raw[i-2]->refInd);
           _raw.erase(_raw.begin()+i-2,_raw.begin()+i);
       }
    }
}