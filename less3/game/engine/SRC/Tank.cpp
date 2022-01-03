//
// Created by lilu on 11/12/2021.
//

#include "Tank.h"
#include "Sprite.h"
#include "Sound.h"


Tank::Tank(Engine *engine, const Shader &shader, glm::vec2 position, glm::vec2 size,
           float rotation, glm::vec2 center): _engine(engine)
{

    _position=position;
    _contentSize = size;
    _rotation = rotation;
    _anchor=center;

    _sounds.push_back(std::make_shared<Sound>("/home/lilu/lilu/cpp_games/cpp_games/less3/game/sound/ehat.wav",
                                              &_engine->audioManager,"move"));
    _sounds.push_back(std::make_shared<Sound>("/home/lilu/lilu/cpp_games/cpp_games/less3/game/sound/puf.wav",
                                              &_engine->audioManager, "puf"));
    //_sounds[0]->stop();
    //_sounds[1]->stop();

    auto body = _engine->createShared<Sprite>(shader, _position, _contentSize, _rotation, _anchor,
                                     glm::vec4(1.0f, 0.0f, 0.5, 1.0f),"body");
    auto gun = _engine->createShared<Sprite>(shader, glm::vec2(_position.x+0.215f, _position.y + 0.08f),
                                    glm::vec2(0.80f, 0.50f), _rotation, glm::vec2 (19.7f, 17.5f),
                                    glm::vec4(1.0f, 0.0f, 1.0f, 1.0f),"gun");


    addNode(body, 4);
    addNode(gun, 5);
    registerEventHandler();
};

void Tank::init()
{

}
void Tank::registerEventHandler()
{
    _engine->_eventManager.addHandler(
                [this] (const SDL_Event& e)
                {
                    auto keyState = SDL_GetKeyboardState(NULL);

                    if (keyState[SDL_SCANCODE_A]) {
                        _nodes[1]->isLeft = true;
                    }
                    if (!keyState[SDL_SCANCODE_A]) {
                        _nodes[1]->isLeft = false;
                    }
                    if (keyState[SDL_SCANCODE_D]) {
                        _nodes[1]->isRight=true;
                    }
                    if (!keyState[SDL_SCANCODE_D]) {
                        _nodes[1]->isRight= false;
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
                    if (keyState[SDL_SCANCODE_SPACE]) {

                        _engine->scene.addNode(_engine->createShared<Sprite>(ResourceManager::GetShader("sprite"),
                                                                    glm::vec2 (_nodes[1]->getPosition().x + 68,
                                                                               _nodes[1]->getPosition().y+8),
                                                                    glm::vec2(10.0f, 10.0f),
                                                                    0.0f, glm::vec2(0.5f),
                                                                    glm::vec4(1.0f, 0.0f,0.0f,0.8f),"fire"),7);

                        _engine->_sounds[0]->pause();
                        _sounds[1]->play();

                    }
                    if (!keyState[SDL_SCANCODE_SPACE]) {
                        _sounds[1]->stop();
                    }
                    if (keyState[SDL_SCANCODE_ESCAPE]) {
                        _engine->isActive = false;
                    }
                    if(keyState[SDL_SCANCODE_UP])
                    {
                        _engine->_sounds[0]->pause();
                        _sounds[0]->play();

                        _nodes[0]->isMovingForward = true;


                    }
                    if(!keyState[SDL_SCANCODE_UP])
                    {
                        _nodes[0]->isMovingForward = false;

                    }
                    if(keyState[SDL_SCANCODE_DOWN])
                    {
                        _engine->_sounds[0]->pause();
                        _sounds[0]->play();

                        _nodes[0]->isMovingBack = true;
                    }
                    if(!keyState[SDL_SCANCODE_DOWN])
                    {
                        _nodes[0]->isMovingBack = false;
                    }
                    if(!keyState[SDL_SCANCODE_DOWN] && !keyState[SDL_SCANCODE_UP]
                       && !keyState[SDL_SCANCODE_SPACE])
                    {
                        _engine->_sounds[0]->play();
                    }
                    if(!keyState[SDL_SCANCODE_DOWN] && !keyState[SDL_SCANCODE_UP])
                    {
                        _sounds[0]->pause();
                    }
                    if(keyState[SDL_SCANCODE_KP_PLUS])
                    {
                        _sounds[0]->volumePlus();
                    }
                    if(keyState[SDL_SCANCODE_KP_MINUS])
                    {
                        _sounds[0]->volumeMinus();
                    }
                }
                );


}


void Tank::updateSelf(float delta)
{
    if(_nodes[0]->isLeft)
    {
        moveLeft(_nodes[0], delta);
    }
    if(_nodes[0]->isRight)
    {
        moveRight(_nodes[0], delta);
    }
    if(_nodes[0]->isMovingForward)
    {
        move(_nodes[0], delta);
    }
    if(_nodes[0]->isMovingBack)
    {
        moveBack(_nodes[0], delta);
    }
    if(_nodes[1]->isLeft)
    {
        moveLeft(_nodes[1], delta);
    }
    if(_nodes[1]->isRight)
    {
        moveRight(_nodes[1], delta);
    }
    _nodes[1] ->setPosition(glm::vec2(_nodes[0]->getPosition().x+21.0f,
                                      _nodes[0]->getPosition().y+5.0f));
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
}

void Tank::moveLeft(std::shared_ptr<Node> sprite, float delta){
    if(std::abs(sprite->_turnSpeed < 70.1f))
    {
        sprite->_turnSpeed = delta*15000.0f + sprite->_speed*0.02;
    }
    if(sprite->_turnSpeed >  0.1f)
    {
        sprite->setRotation(sprite->getRotation() - delta * sprite->_turnSpeed);
        sprite->_turnSpeed -= delta *13500.13f;
    }

    if(sprite->_turnSpeed <0.1f)
    {
        sprite->_turnSpeed = 0.0f;
    }
}

void Tank::moveRight(std::shared_ptr<Node> sprite, float delta){
    if(std::abs(sprite->_turnSpeed < 70.02f))
    {
        sprite->_turnSpeed = -delta*15000.0f - sprite->_speed*0.02;
    }
    if(sprite->_turnSpeed <  -0.1f)
    {
        sprite->setRotation(sprite->getRotation() - delta * sprite->_turnSpeed);
        sprite->_turnSpeed += delta * 13500.13f;
    }

    if(sprite->_turnSpeed > -0.001f)
    {
        sprite->_turnSpeed = 0.0f;
    }
}

void Tank::move(std::shared_ptr<Node> sprite, float delta)
{
    if (sprite->_speed < 40.0f) {
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
}

void Tank::shoot(std::shared_ptr<Node> sprite, float delta)
{
    if (sprite->_speed < 150.0f) {
        sprite->_speed += delta * 2500.0f;
    }

    auto vector = glm::rotate(glm::vec2(1.0f, 0.0f),
                              glm::radians(_nodes[1]->getRotation()));

    if (sprite->_speed > 0.1f)
    {
        sprite->setPosition(sprite->getPosition()+ vector * static_cast<float>(delta) * sprite->_speed);
        sprite->_speed -= delta * 2200.0f;
    }
}

void Tank::moveBack(std::shared_ptr<Node> sprite, float delta)
{
    if(sprite->_speed > -30.0f)
    {
        sprite->_speed -= delta * 1500.0f;
    }

    auto vector = glm::rotate(glm::vec2(1.0f, 0.0f),
                              glm::radians(sprite->getRotation()));
    if(sprite->_speed < -0.1f)
    {
        sprite->setPosition(sprite->getPosition() + vector * delta * sprite ->_speed);
        sprite->_speed += delta * 1300.5f;
    }
    if(sprite->_speed > -0.1f)
    {
        sprite->_speed=0.0f;
    }
}
