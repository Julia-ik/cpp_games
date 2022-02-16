//
// Created by lilu on 01/02/2022.
//

#include "BallRaw.h"
#include "LevelBall.h"
#include "Engine.h"
#include "Particles.h"

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

    for(int o=0;o<_initialSize;o++)
    {
        auto ball = _engine->createShared<LevelBall>(_initialPoint,
                                                     glm::vec2(3.0f, 3.0f), 0.0f, 500.0f,
                                                     std::make_shared<BallRaw>(*this), colorBall[k]);
        k++;
        ball->_tempPoint = _initialPoint;
        ball->_shouldUpdate=false;
        ball->_isInitialized = false;
        if(o==0)
        {
            ball->_shouldUpdate=true;
        }

        this->addNode(ball, 4);
        _raw.emplace_back(ball);
    }
}

void BallRaw::update()
{
    if(_raw.size()>0 && !_engine->isPaused)
    {
        for (int o = 0; o < _raw.size() - 1; o++)
        {
            if ((abs(_raw[o]->getPosition().x - _raw[o + 1]->getPosition().x) > 48.0f
                 && abs(_raw[o]->getPosition().x - _raw[o + 1]->getPosition().x) < 50.0f) ||
                (abs(_raw[o]->getPosition().y - _raw[o + 1]->getPosition().y) > 48.0f
                 && abs(_raw[o]->getPosition().y - _raw[o + 1]->getPosition().y) < 50.0f))
            {
                if(_raw[o + 1]->_isInitialized == false)
                {
                    _raw[o + 1]->_isInitialized = true;
                }
                _raw[o + 1]->_shouldUpdate = true;
                _raw[o]->_shouldUpdate = true;
            }
            if(abs(_raw[o]->getPosition().x - _raw[o+1]->getPosition().x) >= 50.0f ||
               abs(_raw[o]->getPosition().y - _raw[o+1]->getPosition().y) >= 50.0f)
            {
                _raw[o]->_shouldUpdate = false;
                _raw[o+1]->_shouldUpdate = true;
            }
            if ((abs(_raw[o]->getPosition().x - _raw[o + 1]->getPosition().x) <= 48.0f) &&
                (abs(_raw[o]->getPosition().y - _raw[o + 1]->getPosition().y) <= 48.0f))
            {
                if(_raw[o + 1]->_isInitialized && _raw[o]->_isInitialized
                && _raw[o + 1]->_tempPoint == _raw[o]->_tempPoint)
                {
                    _raw[o + 1]->_shouldUpdate = false;
                    _raw[o]->_shouldUpdate = true;
                }
            }
            if(_isLevelFinished)
            {
                _raw[o + 1]->_shouldUpdate = true;
                _raw[o]->_shouldUpdate = true;
            }
        }

        deleteMatch();
        checkFinish();

    }

}
void BallRaw::checkFinish()
{
    if(abs(_raw[0]->getPosition().x - _finalPoint.x)<1.0f &&
       abs(_raw[0]->getPosition().y - _finalPoint.y)<1.0f)
    {
        for(int i =0; i<_raw.size();i++)
        {
            _raw[i]->_speedRaw = 600.0f;
        }
        _isLevelFinished = true;
    }
}
void BallRaw::deleteMatch()
{
    for(int i=0; i<_raw.size(); i++)
    {
       if(i>1 && _raw[i]->_colorIndex == _raw[i-1]->_colorIndex && _raw[i]->_colorIndex == _raw[i-2]->_colorIndex)
       {

           auto emitter = _engine->createShared<Particles>();
           emitter->start(5000, 0.0002f, 0.5f);
           emitter->setRenderMask(0x1);
           emitter->setPosition(_raw[i-1]->getPosition());
           _engine->scene.addNode(emitter,8);

           printf("\n deleting %d, %d, %d", _raw[i]->refInd, _raw[i-1]->refInd, _raw[i-2]->refInd);

           this->removeNodeByInd(_raw[i]->refInd);
           this->removeNodeByInd(_raw[i-1]->refInd);
           this->removeNodeByInd(_raw[i-2]->refInd);
           if(_raw.size()==3)
           {
               _raw.clear();
           }
           else
           {
               _raw.erase(_raw.begin()+i-2,_raw.begin()+i+1);
           }
       }
    }
}