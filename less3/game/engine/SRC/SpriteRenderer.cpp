//
// Created by lilu on 04.12.2021.
//

#include "SpriteRenderer.h"
#include <cstdio>

SpriteRenderer::SpriteRenderer(const Shader &shader, glm::vec2 position, glm::vec2 size,float rotation, float center)
{
    this->shader = shader;
    _position=position;
    _size = size;
    _rotation = rotation;
    _center=center;
    _currentRotation = East;
    this->initRenderData();
}

SpriteRenderer::~SpriteRenderer()
{
    glDeleteVertexArrays(1, &this->quadVAO);
}

void SpriteRenderer::DrawSprite(const Texture &texture)
{
    // Подготовка преобразований
    this->shader.Use();
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(_position, 0.0f));  // сначала выполняем перемещение (преобразования таковы: первым происходит масштабирование, затем поворот, а в конце - перенос; обратный порядок)

    model = glm::translate(model, glm::vec3(_center * _size.x, 0.5f * _size.y, 0.0f)); // перемещаем точку начала поворота в центр прямоугольника
    model = glm::rotate(model, glm::radians(_rotation), glm::vec3(0.0f, 0.0f, 1.0f)); // затем производим поворот
    model = glm::translate(model, glm::vec3(-_center * _size.x, -0.5f * _size.y, 0.0f)); // возвращаем точку поворота в исходную позицию

    model = glm::scale(model, glm::vec3(_size, 1.0f)); // последним выполняется масштабирование

    this->shader.SetMatrix4("model", model);

    // Рендерим текстурированный прямоугольник


    glActiveTexture(GL_TEXTURE0);
    texture.Bind();

    glBindVertexArray(this->quadVAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}

void SpriteRenderer::initRenderData()
{
    // Конфигурируем VAO/VBO
    unsigned int VBO;
    float vertices[] = {
            0.0f, 1.0f, 0.0f, 1.0f,
            1.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 0.0f,

            0.0f, 1.0f, 0.0f, 1.0f,
            1.0f, 1.0f, 1.0f, 1.0f,
            1.0f, 0.0f, 1.0f, 0.0f
    };

    glGenVertexArrays(1, &this->quadVAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(this->quadVAO);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}
void SpriteRenderer::setNextRotation(){
    _currentRotation == 7 ?
            _currentRotation = static_cast<Rotations>(0) :
            _currentRotation = static_cast<Rotations>(static_cast<int>(_currentRotation + 1));
}
void SpriteRenderer::setPreviousRotattion(){
    _currentRotation == 0 ?
            _currentRotation = static_cast<Rotations>(7) :
            _currentRotation = static_cast<Rotations>(static_cast<int>(_currentRotation - 1));
}