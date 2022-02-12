//
// Created by lilu on 08/02/2022.
//

#ifndef ZUMA_PARTICLEBUFFER_H
#define ZUMA_PARTICLEBUFFER_H

#include "VertexBuffer.h"

class color_t;

class ParticleBuffer
{
public:
    struct ParticleData
    {
        glm::vec2 pos;
        glm::vec2 velocity;
        color_t _color = glm::vec4(1, 0, 0, 1);
        float phase = 0;
    };

    ParticleBuffer(std::vector<ParticleData> data);
    ParticleBuffer(size_t capacity);
    //void draw() override;
    void addData(ParticleData data);
    ~ParticleBuffer();

protected:
    uint32_t _VAO = 0;
    uint32_t _VBO = 0;

    uint32_t _count;

    bool _isDynamic = false;
    uint32_t _capacity = 0;
    uint32_t _curPos = 0;

    void createBuffers();
    void createLayouts();

};


#endif //ZUMA_PARTICLEBUFFER_H
