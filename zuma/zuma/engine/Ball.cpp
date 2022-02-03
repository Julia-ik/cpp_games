//
// Created by lilu on 20/01/2022.
//

#include "Ball.h"
#include "Engine.h"
#include <glm/gtx/vector_angle.hpp>

Ball::Ball(const Engine& engine, glm::vec2 position, glm::vec2 size,
float rotation, float speed) : _engine(engine)
{
    {
        _position=position;
        _contentSize = size;
        _rotation = rotation;
        _speed = speed;
        _sprite = _engine.createShared<Sprite>(ResourceManager::GetShader("sprite"),
                                              _position, _contentSize,
                                              _rotation, glm::vec2(0.5f, 0.5f),
                                              "/home/lilu/lilu/cpp_games/cpp_games/less3/game/images/fire2.png");
        //_sprite->setScale(glm::vec2{0.1});
        this->addNode(_sprite, 7);


    }

}
void Ball::updateSelf(float delta)
{
    //_rotation =  glm::degrees(glm::orientedAngle(glm::vec2(1.0f, 0.0f), glm::normalize(_speed)));

    if(_shouldUpdate) {
        auto vector = glm::rotate(glm::vec2(1.0f, 0.0f),
                                  glm::radians(_rotation));
        _nodes[0]->setPosition(_nodes[0]->getPosition() + vector * delta * 100.0f);


        for (int i = 0; i < _engine._ballRaw->_raw.size(); i++) {
            if ((_nodes[0]->getPosition().x >= _engine._ballRaw->_raw[i]->getPosition().x
                 && _nodes[0]->getPosition().x <= _engine._ballRaw->_raw[i]->getPosition().x + 50.0f)
                && (_nodes[0]->getPosition().y >= _engine._ballRaw->_raw[i]->getPosition().y
                    && _nodes[0]->getPosition().y <= _engine._ballRaw->_raw[i]->getPosition().y + 50.0f)) {
                _shouldUpdate = false;

                auto lvlball = std::make_shared<LevelBall>(_engine, glm::vec2(500.0, 600.0),
                                                           glm::vec2(3.0f, 3.0f), 0.0f, 500.0f,
                                                           _engine._ballRaw);
                lvlball->_tempPoint = _engine._ballRaw->_raw[i]->_tempPoint;
                lvlball->setPosition(_engine._ballRaw->_raw[i]->getPosition());
                lvlball->setRotation(_engine._ballRaw->_raw[i]->getRotation());
                lvlball->_nodes[0]->setPosition(_engine._ballRaw->_raw[i]->getPosition());
                lvlball->_nodes[0]->setRotation(_engine._ballRaw->_raw[i]->getRotation());

                _engine._ballRaw->_raw.emplace_back(lvlball);
                //_nodes[0]->setPosition(_nodes[0]->getPosition());
            }
        }
        //_transform = std::nullopt;
    } else{
        ВОТ ТУТ НАДО УДАЛЯТЬ Я НЕ ЗНАЮ КАК УДАЛЯТЬ СЕБЯ ПАМАГИТИ
    }
    
      /*  if (sprite->_speed < 40.0f) {
            sprite->_speed += delta * 2000.0f;
        }

        auto vector = glm::rotate(glm::vec2(1.0f, 0.0f),
                                  glm::radians(sprite->getRotation()));

        if (sprite->_speed > 0.1f) {
            sprite->setPosition(sprite->getPosition() + vector * delta * sprite->_speed);
            sprite->_speed -= delta * 1800.0f;

        }
        if (sprite->_speed < 0.1f) {
            sprite->_speed = 0.0f;
        }
    }*/
}

Ball::~Ball() {

}
