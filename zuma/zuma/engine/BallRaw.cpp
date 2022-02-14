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
        if(o==0)
        {
            ball->_shouldUpdate=true;
        }

        _engine->scene.addNode(ball, 4);
        _raw.emplace_back(ball);
    }

//    _emitter = engine->createShared<Particles>();
//    _emitter->start(5000, 0.0002f, 1.0);
//    _emitter->setRenderMask(0x1);
//    _engine->scene.addNode(_emitter,6);

}

void BallRaw::update()
{
    if(_raw.size()>0 && !_engine->isPaused)
    {
        for (int o = 0; o < _raw.size() - 1; o++) {
            if ((abs(_raw[o]->getPosition().x - _raw[o + 1]->getPosition().x) > 46.0f
                 && abs(_raw[o]->getPosition().x - _raw[o + 1]->getPosition().x) < 50.0f) ||
                (abs(_raw[o]->getPosition().y - _raw[o + 1]->getPosition().y) > 46.0f
                 && abs(_raw[o]->getPosition().y - _raw[o + 1]->getPosition().y) < 50.0f))
            {
                _raw[o + 1]->_shouldUpdate = true;
                _raw[o]->_shouldUpdate = true;
            }
            if(abs(_raw[o]->getPosition().x - _raw[o+1]->getPosition().x) >= 50.0f ||
               abs(_raw[o]->getPosition().y - _raw[o+1]->getPosition().y) >= 50.0f)
            {
                _raw[o]->_shouldUpdate = false;
            }
        }

        deleteMatch();


        if(abs(_raw[0]->getPosition().x - _finalPoint.x)<1.0f &&
        abs(_raw[0]->getPosition().y - _finalPoint.y)<1.0f)
        {
            for(int i =0; i<_raw.size();i++)
            {
                _raw[i]->_speedRaw = 600.0f;
            }
        }
    }

}

void BallRaw::deleteMatch()
{
    for(int i=0; i<_raw.size(); i++)
    {
       if(i>1 && _raw[i]->_colorIndex == _raw[i-1]->_colorIndex && _raw[i]->_colorIndex == _raw[i-2]->_colorIndex)
       {
//           if (_emitter->getParent() == nullptr)
//           {
//               _engine->scene.addNode(_emitter,6);
//           }
//           _emitter->setPosition(_raw[i]->getPosition());
//           _emitter->start(1000);

           _engine->dataToClear.emplace_back(_raw[i]->refInd);
           _engine->dataToClear.emplace_back(_raw[i-1]->refInd);
           _engine->dataToClear.emplace_back(_raw[i-2]->refInd);
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