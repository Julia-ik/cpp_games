//
// Created by lilu on 08/02/2022.
//

#include "ParticleBuffer.h"
#define GLEW_NO_GLU
#include <GL/glew.h>
#include <stdexcept>

ParticleBuffer::ParticleBuffer(std::vector<ParticleData> data)
{
    this->createBuffers();

    glBindBuffer(GL_ARRAY_BUFFER, _VBO);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(ParticleData), data.data(), GL_STATIC_DRAW);

    this->createLayouts();

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    _count = data.size();
}

ParticleBuffer::ParticleBuffer( size_t capacity)
{
    this->createBuffers();

    glBindBuffer(GL_ARRAY_BUFFER, _VBO);
    glBufferData(GL_ARRAY_BUFFER, capacity * sizeof(ParticleData), nullptr, GL_STREAM_DRAW);

    this->createLayouts();

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    _count = 0;
    _curPos = 0;
    _capacity = capacity;

    _isDynamic = true;

}

/*void ParticleBuffer::draw()
{
    if (_count > 0)
    {

#if GLES20
        glBindVertexArrayOES(_VAO);
#elif GL33
        glBindVertexArray(_VAO);
#endif

        glDrawArrays(GL_POINTS, 0, _count);
    }
}
*/
void ParticleBuffer::createBuffers()
{
#if GLES20
    glGenVertexArraysOES(1, &_VAO);

    glBindVertexArrayOES(_VAO);
#elif GL33
    glGenVertexArrays(1, &_VAO);

    glBindVertexArray(_VAO);
#endif
    glGenBuffers(1, &_VBO);
}

void ParticleBuffer::createLayouts()
{
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2,
                          GL_FLOAT, GL_FALSE,  sizeof(ParticleData), (void*)offsetof(ParticleData, pos));

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2,
                          GL_FLOAT, GL_FALSE,  sizeof(ParticleData), (void*)offsetof(ParticleData, velocity));

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 4,
                          GL_UNSIGNED_BYTE, GL_TRUE,  sizeof(ParticleData), (void*)offsetof(ParticleData, _color));

    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 1,
                          GL_FLOAT, GL_FALSE,  sizeof(ParticleData), (void*)offsetof(ParticleData, phase));
}

void ParticleBuffer::addData(ParticleBuffer::ParticleData data)
{
    if (!_isDynamic)
    {
        throw std::logic_error("Can not update static buffer");
    }

    glBindBuffer(GL_ARRAY_BUFFER, _VBO);
    glBufferSubData(GL_ARRAY_BUFFER, _curPos * sizeof(ParticleData), sizeof(ParticleData), &data);

    ++_curPos;

    if (_count < _capacity)
    {
        ++_count;
    }

    _curPos %= _capacity;
}

ParticleBuffer::~ParticleBuffer()
{
    glDeleteBuffers(1, &_VBO);

#if GLES20
    glDeleteVertexArraysOES(1, &_VAO);
#elif GL33
    glDeleteVertexArrays(1, &_VAO);
#endif

}
