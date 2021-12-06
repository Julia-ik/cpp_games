//
// Created by lilu on 30.11.2021.
//

#ifndef GAME_MESH_H
#define GAME_MESH_H
#define GLEW_NO_GLU
#include <glm/vec3.hpp>
#include <SDL.h>
#include <glm/vec2.hpp>
#include <string>
#include <vector>
#include "Shader.h"
#include "library.hpp"


struct Vertex {
    glm::vec2 Position;
    glm::vec2 TexCoords;
};
/*struct Texture {
    unsigned int id;
    std::string type;
};*/
class Mesh {
public:

    Engine *engine;
    Shader shader;

    // Mesh-данные
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Texture> textures;

    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures, Engine *engine);

        void draw(Shader shader);

        // Данные для рендеринга
        unsigned int VAO, VBO, IBO;

        void setupMesh();

};


#endif //GAME_MESH_H
