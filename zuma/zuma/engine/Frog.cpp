//
// Created by lilu on 16/01/2022.
//

#include "Frog.h"
#include "Sprite.h"
#include "ResourceLoader.h"
#include <stdio.h>
#include "Ball.h"
#include "glm/gtx/vector_angle.hpp"


Frog::Frog(Engine *engine, const Shader &shader, glm::vec2 position, glm::vec2 size, float rotation,
           glm::vec2 center) : _engine(engine)
{

    _position=position;
    _contentSize = size;
    _rotation = rotation;
    _anchor=center;

  //  _sounds.push_back(std::make_shared<Sound>("/home/lilu/lilu/cpp_games/cpp_games/less3/game/sound/ehat.wav",
                                         //     &_engine->audioManager,"move"));
    //_sounds.push_back(std::make_shared<Sound>("/home/lilu/lilu/cpp_games/cpp_games/less3/game/sound/puf.wav",
                                             // &_engine->audioManager, "puf"));
    //_sounds[0]->stop();
    //_sounds[1]->stop();

    auto frogBody = _engine->createShared<Sprite>(shader, _position, _contentSize, _rotation, _anchor,
                                              "/home/lilu/lilu/cpp_games/cpp_games/zuma/zuma/engine/images/frog.png",
                                              glm::vec4(0, 0, 1, 1));

    addNode(frogBody, 3);



    registerEventHandler();
    generateBallBanch();
    nextBall = _engine->createShared<Ball>(glm::vec2((_position.x +62.5f) -27.5f, (_position.y+62.5f)-2.5f), _contentSize,
                                           _rotation, 500.0f, colorBall[i]);
    nextBall->setRotation(getRotation()+90.0f);
//315 330
//- 27.5f -2.5f)
    nextBall->_shouldUpdate = false;
    addNode(nextBall, 4);
};

//void Frog::init()
//{
//
//}
void Frog::registerEventHandler()
{
    _engine->_eventManager.addHandler(

            [this] (const SDL_Event& e)
            {
                auto keyState = SDL_GetKeyboardState(NULL);

                if (keyState[SDL_SCANCODE_A]) {
                    _nodes[0]->isLeft = true;
                }
                if (!keyState[SDL_SCANCODE_A]) {
                    _nodes[0]->isLeft = false;
                }
                if (keyState[SDL_SCANCODE_D]) {
                    _nodes[0]->isRight=true;
                }
                if (!keyState[SDL_SCANCODE_D]) {
                    _nodes[0]->isRight= false;
                }
                if (keyState[SDL_SCANCODE_LEFT]) {
                    //_spriteRenderers["body"]->_isLeft=true;
                    _nodes[0]->isLeft=true;

                }
                if (!keyState[SDL_SCANCODE_LEFT]) {
                    //_spriteRenderers["body"]->_isLeft=true;
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

                    i++;
                    auto ball = _engine->createShared<Ball>(nextBall->getPosition(), glm::vec2(3.0f, 3.0f),
                                                            nextBall->getRotation(), 500.0f, colorBall[i]);
                    ball->_shouldUpdate = false;
                    nextBall->_shouldUpdate = true;

                    nextBall = ball;
                    _engine->scene.addNode(nextBall, 5);


//                  auto vector = glm::rotate(glm::vec2{1.0f, 0.0f},
//                                             glm::radians(_nodes[0]->getRotation()));
                    /*_engine->scene.addNode(nextBall, 5);
                    nextBall->_shouldUpdate = false;
                   auto ball = _engine->createShared<Ball>(_position, glm::vec2(3.0f, 3.0f),
                                                           _nodes[0]->getRotation()+90.0f, 500.0f, colorBall[i]);
                   i++;


                   // ball->setPosition(_position + vector);
                    _engine->scene.addNode(ball, 4);*/


//                   _engine->_sounds[0]->pause();
//                  _sounds[1]->play();
               }
                if (!keyState[SDL_SCANCODE_SPACE]) {
                  //  _sounds[1]->stop();
                }
                if (keyState[SDL_SCANCODE_ESCAPE]) {
                    _engine->isActive = false;
                }
                if(keyState[SDL_SCANCODE_DOWN])
                {
                    //_engine->_sounds[0]->pause();
                    //_sounds[0]->play();

                    //_nodes[0]->isMovingBack = true;
                }
                if(!keyState[SDL_SCANCODE_DOWN])
                {
                    //_nodes[0]->isMovingBack = false;
                }
                if(!keyState[SDL_SCANCODE_DOWN] && !keyState[SDL_SCANCODE_UP]
                   && !keyState[SDL_SCANCODE_SPACE])
                {
                   // _engine->_sounds[0]->play();
                }
                if(!keyState[SDL_SCANCODE_DOWN] && !keyState[SDL_SCANCODE_UP])
                {
                    //_sounds[0]->pause();
                }
                if(keyState[SDL_SCANCODE_KP_PLUS])
                {
                   // _sounds[0]->volumePlus();
                }
                if(keyState[SDL_SCANCODE_KP_MINUS])
                {
                    //_sounds[0]->volumeMinus();
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
           auto _mousePos = glm::vec2{e.motion.x, e.motion.y};
            _rotation =  glm::degrees(glm::orientedAngle(glm::vec2(0.0f, 1.0f),
                                                         glm::normalize(_mousePos- _nodes[0]->getPosition())));
            _nodes[0]->setRotation(_rotation);

            auto vector =   glm::normalize(_mousePos- _nodes[0]->getPosition());
            auto ball = _engine->createShared<Ball>(_position, glm::vec2(3.0f, 3.0f),
                                                    _nodes[0]->getRotation()+90.0f, 500.0f, colorBall[i]);
            i++;
            if(i == 100){
                generateBallBanch();
            }

            ball->setPosition(_position + vector);
            _engine->scene.addNode(ball, 4);

        }
    });


}

void Frog::updateSelf(float delta) {

    if (_nodes[0]->isLeft) {
        moveLeft(_nodes[0], delta);
    }
    if (_nodes[0]->isRight) {
        moveRight(_nodes[0], delta);
    }
}
//    if (_nodes[1]->isLeft) {
//        moveLeft(_nodes[1], delta);
//    }
//    if (_nodes[1]->isRight) {
//        moveRight(_nodes[1], delta);
//    }
//
//
//    _nodes[1]->setPosition(glm::vec2(_nodes[0]->getPosition().x + 21.0f, _nodes[0]->getPosition().y + 5.0f));

//void Frog::shoot(std::shared_ptr<Node> sprite, float delta)
//{
//    if (sprite->_speed < 150.0f) {
//        sprite->_speed += delta * 2500.0f;
//    }
//
//    auto vector = glm::rotate(glm::vec2(1.0f, 0.0f),
//                              glm::radians(_nodes[0]->getRotation()));
//
//    if (sprite->_speed > 0.1f)
//    {
//        sprite->setPosition(sprite->getPosition()+ vector * static_cast<float>(delta) * sprite->_speed);
//        sprite->_speed -= delta * 2200.0f;
//    }
//}




    /*if(_engine->scene.getNodes().size() > 5)
    {
        for(int i=2;i<_engine->scene.getNodes().size(); i++)
        {
            shoot(_engine->scene.getNodes()[i], delta);
            if(_engine->scene.getNodes()[i]->getPosition().x > _engine->width ||
                    _engine->scene.getNodes()[i]->getPosition().y > _engine->heights)
            {
             //   _engine->scene.removeNode(_engine->scene.getNodes()[]);
            }
        }

    }*/
    /*str2.erase(std::remove_if(str2.begin(),
                              str2.end(),
                              [](unsigned char x){return std::isspace(x);}),
               str2.end());
    std::cout << str2 << '\n';*/
    /*for(int i=0; i<_sounds.size();i++)
    {
        if(_sounds[i].expired())
        {
            _engine->audioManager._buffers.erase(_sounds[i].lock()->_name);
        }
    }*/
//}


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

        printf("\n HUI  %d\n", nextBall->_colorIndex);
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

//void Frog::shoot(std::shared_ptr<Node> sprite, float delta)
//{
//    if (sprite->_speed < 150.0f) {
//        sprite->_speed += delta * 2500.0f;
//    }
//
//    auto vector = glm::rotate(glm::vec2(1.0f, 0.0f),
//                              glm::radians(_nodes[0]->getRotation()));
//
//    if (sprite->_speed > 0.1f)
//    {
//        sprite->setPosition(sprite->getPosition()+ vector * static_cast<float>(delta) * sprite->_speed);
//        sprite->_speed -= delta * 2200.0f;
//    }
//}

void Frog::generateBallBanch()
{
    colorBall =  _engine->chooseColor(100);
}

