//
// Created by lilu on 04.12.2021.
//

#include "Sprite.h"
#include "library.hpp"
#include "Uniforms.h"

Sprite::Sprite(const Engine &engine, const Shader &shader, glm::vec2 position, glm::vec2 size, float rotation, glm::vec2 center,
               glm::vec4 col, std::string filepath) :_color(col), _engine(engine)
{

    this->shader = shader;
    _position=position;
    _contentSize = size;
    _rotation = rotation;
    _anchor=center;

    _filepath = filepath;

    this->initRenderData();

}

Sprite::~Sprite()
{
    glDeleteVertexArrays(1, &this->quadVAO);
}

void Sprite::visitSelf()
{
    _screenSizeUniform->value.x = _engine.width;
    _screenSizeUniform->value.y = _engine.heights;

    _transformUniform->value = this->getTransform();

    _engine._renderer->addCommand(_command);

}

void Sprite::initRenderData()
{
    Bitmap bitmap(_filepath);
    meshData.vertices.emplace_back();
    meshData.vertices.back().position = {0.0, 0.0};
    meshData.vertices.back().textureCoords = {0.0, 0.0};

    meshData.vertices.emplace_back();
    meshData.vertices.back().position = {0.0, bitmap.getSize().y};
    meshData.vertices.back().textureCoords = {0.0, 1.0};

    meshData.vertices.emplace_back();
    meshData.vertices.back().position = {bitmap.getSize().x, bitmap.getSize().y};
    meshData.vertices.back().textureCoords = {1.0, 1.0};

    meshData.vertices.emplace_back();
    meshData.vertices.back().position = {bitmap.getSize().x, 0.0};
    meshData.vertices.back().textureCoords = {1.0, 0.0};

    meshData.indexes.emplace_back(0);
    meshData.indexes.emplace_back(2);
    meshData.indexes.emplace_back(3);

    meshData.indexes.emplace_back(0);
    meshData.indexes.emplace_back(1);
    meshData.indexes.emplace_back(2);


    _command.vertexBuffer = _engine._renderer->createVertexBuffer(std::move(meshData));
    _command.program = std::make_shared<Shader>(shader);

    _textureUniform = _command.program->createTextureUniform("uTexture", _command.program);
    _textureUniform->texture = _engine._renderer->createTexture(std::move(bitmap));

    _screenSizeUniform = _command.program->createVec2Uniform("uScreenSize", _command.program);
    _transformUniform = _command.program->createMat3Uniform("uTransform", _command.program);

    _command._transformUniform = _transformUniform;
    _command._screenSizeUniform = _screenSizeUniform;
    _command._textureUniform = _textureUniform;
}

