//
// Created by lilu on 04.12.2021.
//

#ifndef GAME_SPRITERENDERER_H
#define GAME_SPRITERENDERER_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Texture.h"
#include "Shader.h"

enum Rotations{
    North=0,
    NorthEast=1,
    East=2,
    SouthEast=3,
    South=4,
    SouthWest=5,
    West=6,
    NorthWest=7
};

class SpriteRenderer
{
public:

    glm::vec2 _position;
    glm::vec2 _size;
    float _rotation;
    float _center;
    Rotations _currentRotation;
    // Конструктор (инициализируем шейдеры/объекты)
    SpriteRenderer(const Shader &shader, glm::vec2 position, glm::vec2 size,float rotation, float center);

    // Деструктор
    ~SpriteRenderer();

    // Рендерим текстурированный прямоугольник по заданному спрайту
    void DrawSprite(const Texture &texture);
    void setNextRotation();
    void setPreviousRotattion();

private:
    // Состояние рендера
    Shader shader;
    unsigned int quadVAO;

    // Инициализируем и настраиваем атрибуты буфера и атрибуты вершин
    void initRenderData();
};


#endif //GAME_SPRITERENDERER_H
