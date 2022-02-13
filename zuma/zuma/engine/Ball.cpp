//
// Created by lilu on 20/01/2022.
//

#include "Ball.h"
#include "Engine.h"
#include <glm/gtx/vector_angle.hpp>

Ball::Ball(const Engine& engine, glm::vec2 position, glm::vec2 size,
float rotation, float speed, int colorIndex) : _engine(engine)
{
    {
        _position=position;
        _contentSize = size;
        _rotation = rotation;
        _speed = speed;
        _colorIndex = colorIndex;
        auto _color = getColorFromIndex(colorIndex);

        _sprite = _engine.createShared<Sprite>(_position, glm::vec2(0.07f, 0.07f),
                                              _rotation, glm::vec2(400.0f, 400.0f),
                                              "/home/lilu/lilu/cpp_games/cpp_games/zuma/zuma/engine/images/shar.png",
                                              _color);

    }

        this->addNode(_sprite, 7);
}
void Ball::updateSelf(float delta)
{
    //_rotation =  glm::degrees(glm::orientedAngle(glm::vec2(1.0f, 0.0f), glm::normalize(_speed)));
    _nodes[0]->_color = getColorFromIndex(_colorIndex);

    if(_shouldUpdate) {
        auto vector = glm::rotate(glm::vec2(1.0f, 0.0f),
                                  glm::radians(_rotation));
        _nodes[0]->setPosition(_nodes[0]->getPosition() + vector * delta * 300.0f);


         for (int i = 0; i < _engine._ballRaw->_raw.size(); i++) {
             if ((_nodes[0]->getPosition().x >= _engine._ballRaw->_raw[i]->getPosition().x
                  && _nodes[0]->getPosition().x <= _engine._ballRaw->_raw[i]->getPosition().x + 45.0f)
                 && (_nodes[0]->getPosition().y >= _engine._ballRaw->_raw[i]->getPosition().y
                     && _nodes[0]->getPosition().y <= _engine._ballRaw->_raw[i]->getPosition().y + 45.0f)) {

                auto lvlball = std::make_shared<LevelBall>(_engine, glm::vec2(_engine._ballRaw->_initialPoint),
                                                            glm::vec2(3.0f, 3.0f), 0.0f, 500.0f,
                                                            _engine._ballRaw, _colorIndex);
                 lvlball->_tempPoint = _engine._ballRaw->_raw[i]->_tempPoint;
                 lvlball->j = _engine._ballRaw->_raw[i]->j;
                 lvlball->setPosition(_engine._ballRaw->_raw[i]->getPosition());
                 lvlball->setRotation(_engine._ballRaw->_raw[i]->getRotation());
                 lvlball->_nodes[0]->setPosition(_engine._ballRaw->_raw[i]->getPosition());
                 lvlball->_nodes[0]->setRotation(_engine._ballRaw->_raw[i]->getRotation());

                 for (int m = 0; m <= i; m++)
                 {
                     for(int l=0; l<75; l++)
                     {
                         _engine._ballRaw->_raw[m]->updateSelf(0.01f);
                     }
                 }

                 _engine.scene.addNode(lvlball, 5);
                 _engine._ballRaw->_raw.insert(_engine._ballRaw->_raw.begin() +i+1, lvlball);
                _engine.dataToClear.emplace_back(refInd);
                 break;
            }
        }
    } else{
        _nodes[0]->setPosition(_position);

        _nodes[0]->setRotation(_rotation);
    }




}

glm::vec4 Ball::getColorFromIndex(int colorIndex)
{
    switch (colorIndex)
    {
        case ORANGE:
            return glm::vec4(1, 0.5f, 0,1);
        case PURPLE:
            return glm::vec4(0.5f, 0, 0.5f, 1);
        case BLUE:
            return glm::vec4(0, 0, 1, 1);
        case YELLOW:
            return glm::vec4(1, 1, 0, 1);
        default:
            return glm::vec4(1, 1, 1, 1);
    }

}

Ball::~Ball() {

}
