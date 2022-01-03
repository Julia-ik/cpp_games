//
// Created by lilu on 04.12.2021.
//

#ifndef GAME_SPRITE_H
#define GAME_SPRITE_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Texture.h"
#include "Node.h"
#include "Color.h"
#include "Shader.h"
#include <string>
#include "Bitmap.h"
#include "Renderer.h"
#include "ResourceLoader.h"
#include "MeshData.h"

class Engine;
class Sprite: public Node
{
public:
    MeshData meshData;
    const Engine &_engine;
    Renderer::Command _command;
    // Конструктор (инициализируем шейдеры/объекты)
    Sprite(const Engine &_engine, const Shader &shader, glm::vec2 position, glm::vec2 size, float rotation, glm::vec2 center,
           glm::vec4 col, std::string textureName);

    // Деструктор
    ~Sprite();

    // Рендерим текстурированный прямоугольник по заданному спрайту
    void  visitSelf() override;
    glm::vec4 _color;


private:
    // Состояние рендера
    Shader shader;
    Texture _texture;
    unsigned int quadVAO;

    // Инициализируем и настраиваем атрибуты буфера и атрибуты вершин
    void initRenderData();
};


#endif //GAME_SPRITE_H
