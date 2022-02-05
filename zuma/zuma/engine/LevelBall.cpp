//
// Created by lilu on 02/02/2022.
//

#include "LevelBall.h"
#include "BallRaw.h"
#include <cmath>


LevelBall::LevelBall(const Engine& engine, glm::vec2 position, glm::vec2 size,
                     float rotation, float speed, std::shared_ptr<BallRaw> raw, int colorIndex)
                     : Ball(engine, position, size, rotation, speed, colorIndex), _ballraw(raw)
{
}



void LevelBall::updateSelf(float delta)
{
    if(abs(_tempPoint.x - _position.x)>0.0f ||
            abs(_tempPoint.y - _position.y)>0.0f) {


        auto vec1 = glm::normalize(_tempPoint - _position);
        setPosition(_nodes[0]->getPosition() + vec1 * delta * 60.0f);
        _nodes[0]->setPosition(_position);
        _transform = std::nullopt;
    } else{
        j++;
        if(j<_ballraw->_points.size()){

            _tempPoint = _ballraw->_points[j];
        }
    }

}