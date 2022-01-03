//
// Created by lilu on 04.12.2021.
//

#include "Sprite.h"
#include "library.hpp"

Sprite::Sprite(const Engine &engine, const Shader &shader, glm::vec2 position, glm::vec2 size, float rotation, glm::vec2 center,
               glm::vec4 col, std::string textureName) :_color(col), _engine(engine)
{

    this->shader = shader;
    _position=position;
    _contentSize = size;
    _rotation = rotation;
    _anchor=center;

    _texture = ResourceManager::GetTexture(textureName);
    this->initRenderData();

}

Sprite::~Sprite()
{
    glDeleteVertexArrays(1, &this->quadVAO);
}

void Sprite::visitSelf()
{
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(_position, 0.0f));  // сначала выполняем перемещение (преобразования таковы: первым происходит масштабирование, затем поворот, а в конце - перенос; обратный порядок)

   model = glm::translate(model, glm::vec3(_anchor.x * _contentSize.x,
                                            _anchor.y* _contentSize.y, 0.0f)); // перемещаем точку начала поворота в центр прямоугольника

    model = glm::rotate(model, glm::radians(_rotation), glm::vec3(0.0f, 0.0f, 1.0f)); // затем производим поворот
    model = glm::translate(model, -glm::vec3(_anchor.x * _contentSize.x,
                                            _anchor.y* _contentSize.y, 0.0f)); // возвращаем точку поворота в исходную позицию

    model = glm::scale(model, glm::vec3(_contentSize, 1.0f)); // последним выполняется масштабирование

    _command.transform = model;
    _engine._renderer->addCommand(_command);

    //this->shader.SetVector4f("spriteColor", _color);

}

void Sprite::initRenderData()
{
    meshData.vertices.emplace_back();
    meshData.vertices.back().position = {0.0, 0.0};
    meshData.vertices.back().textureCoords = {0.0, 0.0};

    meshData.vertices.emplace_back();
    meshData.vertices.back().position = {0.0, _texture.Height};
    meshData.vertices.back().textureCoords = {0.0, 1.0};

    meshData.vertices.emplace_back();
    meshData.vertices.back().position = {_texture.Width, _texture.Height};
    meshData.vertices.back().textureCoords = {1.0, 1.0};

    meshData.vertices.emplace_back();
    meshData.vertices.back().position = {_texture.Width, 0.0};
    meshData.vertices.back().textureCoords = {1.0, 0.0};

    meshData.indexes.emplace_back(0);
    meshData.indexes.emplace_back(2);
    meshData.indexes.emplace_back(3);

    meshData.indexes.emplace_back(0);
    meshData.indexes.emplace_back(1);
    meshData.indexes.emplace_back(2);


    _command.vertexBuffer = _engine._renderer->createVertexBuffer(std::move(meshData));
    _command.program = std::make_shared<Shader>(shader);
    _command.texture = std::make_shared<Texture>(_texture);
}

