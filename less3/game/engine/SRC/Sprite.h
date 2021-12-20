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
#include "ResourceLoader.h"


class Sprite: public Node
{
public:

    // Конструктор (инициализируем шейдеры/объекты)
    Sprite(const Shader &shader, glm::vec2 position, glm::vec2 size, float rotation, glm::vec2 center,
           glm::vec4 col, std::string textureName);

    // Деструктор
    ~Sprite();

    // Рендерим текстурированный прямоугольник по заданному спрайту
    void  visitSelf() override;
    glm::vec4 _color;

/*void GlVertexBuffer::draw(size_t num, size_t offset)
{
    glBindVertexArray(_VAO);

    GlDrawElements(GL_TRIANGLES, static_cast<GLsizei>(num),
                   GL_UNSIGNED_INT,
                   reinterpret_cast <GLvoid*>(offset));
}*/


private:
    // Состояние рендера
    Shader shader;
    Texture _texture;
    unsigned int quadVAO;

    // Инициализируем и настраиваем атрибуты буфера и атрибуты вершин
    void initRenderData();
};


#endif //GAME_SPRITE_H
