//
// Created by lilu on 16/01/2022.
//

#include "Frog.h"
#include "Sprite.h"
#include "ResourceLoader.h"
#include <stdio.h>
#include "Ball.h"
#include "glm/gtx/vector_angle.hpp"


Frog::Frog(Engine *engine, glm::vec2 position, glm::vec2 size, float rotation,
           glm::vec2 center) : _engine(engine)
{

    _position=position;
    _contentSize = size;
    _rotation = rotation;
    _anchor=center;


    auto frogBody = _engine->createShared<Sprite>(_position, _contentSize, _rotation, _anchor,
                                              "/home/lilu/lilu/cpp_games/cpp_games/zuma/zuma/engine/images/frog.png",
                                              glm::vec4(1, 1, 1, 1));

    addNode(frogBody, 3);



    registerEventHandler();
    generateBallBanch();

    nextBall = _engine->createShared<Ball>(glm::vec2((_position.x +62.5f) -27.5f, (_position.y+62.5f)-2.5f), _contentSize,
                                           _rotation, 500.0f, colorBall[i]);
    nextBall->setRotation(getRotation()+90.0f);
    nextBall->_shouldUpdate = false;
    _engine->scene.addNode(nextBall, 4);
};

void Frog::registerEventHandler()
{
    _engine->_eventManager.addHandler(

            [this] (const SDL_Event& e)
            {
                auto keyState = SDL_GetKeyboardState(NULL);

                if (keyState[SDL_SCANCODE_LEFT]) {
                    _nodes[0]->isLeft=true;
                }
                if (!keyState[SDL_SCANCODE_LEFT]) {
                    _nodes[0]->isLeft=false;
                }
                if (keyState[SDL_SCANCODE_RIGHT]) {
                    _nodes[0]->isRight=true;
                }
                if (!keyState[SDL_SCANCODE_RIGHT]) {
                    _nodes[0]->isRight=false;
                }
                if (keyState[SDL_SCANCODE_UP])
                {
                    if(!_engine->isPaused)
                    {
                        i++;
                        if(i >= 100){
                            generateBallBanch();
                            i = 0;
                        }
                        auto ball = _engine->createShared<Ball>(nextBall->getPosition(), glm::vec2(3.0f, 3.0f),
                                                                nextBall->getRotation(), 500.0f, nextBall->_colorIndex);

                        _engine->scene.addNode(ball, 4);
                        nextBall->_colorIndex = colorBall[i];
                    }

               }

                if (keyState[SDL_SCANCODE_ESCAPE]) {
                    _engine->isActive = false;
                }

                if(keyState[SDL_SCANCODE_KP_PLUS])
                {
                   _engine->_sounds[0]->volumePlus();
                }
                if(keyState[SDL_SCANCODE_KP_MINUS])
                {
                    _engine->_sounds[0]->volumeMinus();
                }
            }
    );

    _engine->_eventManager.addHandler ([this](const SDL_Event &e)
    {
        if (e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_LEFT)
        {

        }
        else if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
        {
            if(!_engine->isPaused)
            {
                auto _mousePos = glm::vec2{e.motion.x, e.motion.y};
                _rotation =  glm::degrees(glm::orientedAngle(glm::vec2(0.0f, 1.0f),
                                                             glm::normalize(_mousePos- _nodes[0]->getPosition())));
                _nodes[0]->setRotation(_rotation);

                auto vector =   glm::normalize(_mousePos- _nodes[0]->getPosition());
                auto ball = _engine->createShared<Ball>(_position, glm::vec2(3.0f, 3.0f),
                                                        _nodes[0]->getRotation()+90.0f, 500.0f, nextBall->_colorIndex);
                i++;
                if(i >= 100){
                    generateBallBanch();
                    i = 0;
                }

                ball->setPosition(_position + vector);
                _engine->scene.addNode(ball, 4);
                nextBall->_colorIndex = colorBall[i];
            }
        }
    });

}

void Frog::updateSelf(float delta) {

    if(!_engine->isPaused)
    {
        if (_nodes[0]->isLeft) {
            moveLeft(_nodes[0], delta);
        }
        if (_nodes[0]->isRight) {
            moveRight(_nodes[0], delta);
        }
    }

}

void Frog::moveLeft(std::shared_ptr<Node> sprite, float delta){
    if(std::abs(sprite->_turnSpeed < 100.1f))
    {
        sprite->_turnSpeed = delta*30000.0f;
    }
    if(sprite->_turnSpeed >  0.1f)
    {
        sprite->setRotation(sprite->getRotation() - delta * sprite->_turnSpeed);
        sprite->_turnSpeed -= delta *30000.0f;
        auto vec =glm::rotate(glm::vec2{-1.0f, 0.0f}, glm::radians(sprite->getRotation()));

               /* glm::rotate(glm::vec2{0.0f, 1.0f},
                                  glm::radians(sprite->getRotation()));*/
        nextBall->setPosition(nextBall->getPosition() - vec * 0.05f);
//        printf("\n HUI %f, %f\n", nextBall->getPosition().x, nextBall->getPosition().y);
        nextBall->setRotation(sprite->getRotation()+90.0f);

    }

    if(sprite->_turnSpeed <0.1f)
    {
        sprite->_turnSpeed = 0.0f;
    }

}

void Frog::moveRight(std::shared_ptr<Node> sprite, float delta)
{
    if(std::abs(sprite->_turnSpeed < 100.1f))
    {
        sprite->_turnSpeed = -delta*30000.0f;
    }
    if(sprite->_turnSpeed <  -0.1f)
    {
        sprite->setRotation(sprite->getRotation() - delta * sprite->_turnSpeed);
        sprite->_turnSpeed += delta * 30000.0f;

        auto vec =glm::rotate(glm::vec2{-1.0f, 0.0f}, glm::radians(sprite->getRotation()));

        nextBall->setPosition(nextBall->getPosition() + vec * 0.04f);
        nextBall->setRotation(sprite->getRotation()+90.0f);
    }

    if(sprite->_turnSpeed > -0.001f)
    {
        sprite->_turnSpeed = 0.0f;
    }
}

void Frog::generateBallBanch()
{
    colorBall =  _engine->chooseColor(100);
}

