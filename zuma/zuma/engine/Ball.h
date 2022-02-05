//
// Created by lilu on 20/01/2022.
//

#ifndef ZUMA_BALL_H
#define ZUMA_BALL_H


#include "Sprite.h"
class BallRaw;

class Ball: public Node
{
public:
    Ball(const Engine& engine, glm::vec2 position, glm::vec2 size,
         float rotation, float speed, int colorIndex);
    virtual ~Ball();
    void updateSelf(float delta) override;
    bool _shouldUpdate= true;

    int _colorIndex;
protected:
        std::shared_ptr<Sprite> _sprite;
        float _speed;
        const Engine &_engine;
        glm::vec4 getColorFromIndex(int colorIndex);
};


#endif //ZUMA_BALL_H
