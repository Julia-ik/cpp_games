//
// Created by lilu on 16/01/2022.
//

#include <cstdint>
#include "VertexBuffer.h"
#include "Engine.h"

VertexBuffer::VertexBuffer(const Engine &engine, MeshData data)
        :_engine(engine)
{
    glGenVertexArrays(1, &_VAO);

    glBindVertexArray(_VAO);

    glGenBuffers(1, &_VBO);

    glBindBuffer(GL_ARRAY_BUFFER, _VBO);
    glBufferData(GL_ARRAY_BUFFER, data.vertices.size() * sizeof(MeshData::Vertex), data.vertices.data(), GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2,
                          GL_FLOAT, GL_FALSE,  sizeof(MeshData::Vertex), (void*)offsetof(MeshData::Vertex, position));

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2,
                          GL_FLOAT, GL_FALSE,  sizeof(MeshData::Vertex), (void*)offsetof(MeshData::Vertex, textureCoords));

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    //glEnableVertexAttribArray(2);
    //glVertexAttribPointer(2, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof (MeshData::Vertex), (void*) offsetof(MeshData::Vertex, color));


    glGenBuffers(1, &_IBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _IBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                 data.indexes.size() * sizeof(std::uint32_t),
                 data.indexes.data(), GL_STATIC_DRAW);

    _count = data.indexes.size();




}



void VertexBuffer::draw(size_t num, size_t offset)
{
    glBindVertexArray(_VAO);


    glDrawElements(GL_TRIANGLES,
                   static_cast<GLsizei>(num),
                   GL_UNSIGNED_INT,
                   reinterpret_cast<GLvoid*>(offset));
//    GlCheckError(__FILE__, __LINE__);
}

VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &_VBO);

    if (_IBO != 0)
    {
        glDeleteBuffers(1, &_IBO);
    }



#ifdef GLES
    glDeleteVertexArraysOES(1, &_VAO);
#else
    glDeleteVertexArrays(1, &_VAO);
#endif

    // GlCheckError(__FILE__, __LINE__);

}
void VertexBuffer::draw()
{
    this->draw(_count, 0);
}
