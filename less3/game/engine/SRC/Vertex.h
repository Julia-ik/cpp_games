//
// Created by lilu on 15/12/2021.
//

#ifndef GAME_VERTEX_H
#define GAME_VERTEX_H
#include "Color.h"
#include "Sprite.h"


struct Vertex
{
    glm::vec2 position;
    glm::vec2 textureCoords;
    color_t color = glm::vec4(1,1,1,1);



};


#endif //GAME_VERTEX_H
