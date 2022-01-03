//
// Created by lilu on 24/12/2021.
//

#ifndef GAME_MESHDATA_H
#define GAME_MESHDATA_H
#include "glm/glm.hpp"
#include "Color.h"
#include <vector>

class MeshData
{
public:
    struct Vertex
    {
        glm::vec2 position;
        glm::vec2 textureCoords;
        color_t color = glm::vec4(1, 1, 1, 1);
    };

    std::vector<Vertex> vertices;
    std::vector<uint32_t> indexes;
};

#endif //GAME_MESHDATA_H
