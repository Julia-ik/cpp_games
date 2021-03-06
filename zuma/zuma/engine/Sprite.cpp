//
// Created by lilu on 16/01/2022.
//

#include "Sprite.h"
#include "Bitmap.h"
#include "MeshData.h"
#include "Engine.h"

Sprite::Sprite(const Engine &engine, glm::vec2 position, glm::vec2 size, float rotation, glm::vec2 center,
               std::string filepath, glm::vec4 col) : _engine(engine), _bitmap(filepath)
{
    _position=position;
    _contentSize = size;
    _rotation = rotation;
    _anchor=center;
    _color = col;
    _shader = engine._resManager->GetShader("sprite");
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
    _command._transformUniform = _transformUniform;
    _colorUniform->value = _color;

    //_command.vertexBuffer = _engine._renderer->createVertexBuffer(std::move(meshData));

    _engine._renderer->addCommand(_command);

}

void Sprite::initRenderData()
{
    meshData.vertices.emplace_back();
    meshData.vertices.back().position = {0.0, 0.0};
    meshData.vertices.back().textureCoords = {0.0, 0.0};
    meshData.vertices.back().color = _color; //glm::vec4(0, 0, 1, 1);

    meshData.vertices.emplace_back();
    meshData.vertices.back().position = {0.0, _bitmap.getSize().y};
    meshData.vertices.back().textureCoords = {0.0, 1.0};
    meshData.vertices.back().color = _color;

    meshData.vertices.emplace_back();
    meshData.vertices.back().position = {_bitmap.getSize().x, _bitmap.getSize().y};
    meshData.vertices.back().textureCoords = {1.0, 1.0};
    meshData.vertices.back().color = _color;

    meshData.vertices.emplace_back();
    meshData.vertices.back().position = {_bitmap.getSize().x, 0.0};
    meshData.vertices.back().textureCoords = {1.0, 0.0};

    meshData.indexes.emplace_back(0);
    meshData.indexes.emplace_back(2);
    meshData.indexes.emplace_back(3);

    meshData.indexes.emplace_back(0);
    meshData.indexes.emplace_back(1);
    meshData.indexes.emplace_back(2);


    _command.vertexBuffer = _engine._renderer->createVertexBuffer(std::move(meshData));
    _command.program = _shader;

    _textureUniform = _command.program->createTextureUniform("uTexture", _command.program);
    _textureUniform->texture = _engine._renderer->createTexture(std::move(_bitmap));

    _screenSizeUniform = _command.program->createVec2Uniform("uScreenSize", _command.program);

    _colorUniform = _command.program->createVec4Uniform("uColor", _command.program);
    _colorUniform->value = _color;

    _transformUniform = _command.program->createMat3Uniform("uTransform", _command.program);

    _command._transformUniform = _transformUniform;
    _command._screenSizeUniform = _screenSizeUniform;
    _command._textureUniform = _textureUniform;
    _command._colorUniform = _colorUniform;
}

