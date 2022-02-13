//
// Created by lilu on 16/01/2022.
//

#ifndef ZUMA_VERTEXBUFFER_H
#define ZUMA_VERTEXBUFFER_H

#include "MeshData.h"
#include "BaseVertexBuffer.h"
#include <SDL.h>

class Engine;
class VertexBuffer : public BaseVertexBuffer
{
public:
    VertexBuffer(const Engine& engine, MeshData data);

    ~VertexBuffer() override;

    void draw(size_t num, size_t offset);

    virtual void draw();

private:
    uint32_t _VAO = 0;
    uint32_t _VBO = 0;
    uint32_t _IBO = 0;

    uint32_t _count;
    const Engine &_engine;
};

#endif //ZUMA_VERTEXBUFFER_H
