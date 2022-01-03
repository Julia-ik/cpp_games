//
// Created by lilu on 22/12/2021.
//

#include "glParticalBuffer.h"
#include <GL/glew.h>
//вставить кусок из glvertex

void glParticalBuffer::draw()
{
    glBindVertexArray(VAO);
    glDrawArrays(GL_POINT, 0, count);

}