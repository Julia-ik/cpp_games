//
// Created by lilu on 16/01/2022.
//

#ifndef ZUMA_MESHDATA_H
#define ZUMA_MESHDATA_H
#include <glm/glm.hpp>
#include <vector>
#include "Color.h"

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


#endif //ZUMA_MESHDATA_H
