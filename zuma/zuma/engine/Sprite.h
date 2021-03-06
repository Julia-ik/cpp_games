//
// Created by lilu on 16/01/2022.
//

#ifndef ZUMA_SPRITE_H
#define ZUMA_SPRITE_H

#include "Texture.h"
#include "Node.h"
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
    Bitmap _bitmap;

    std::shared_ptr<GlVec2Uniform> _screenSizeUniform;
    std::shared_ptr<GlMat3Uniform>  _transformUniform;
    std::shared_ptr<GlTextureUniform>  _textureUniform;
    std::shared_ptr<GlVec4Uniform> _colorUniform;

    Sprite(const Engine &_engine, glm::vec2 position, glm::vec2 size, float rotation, glm::vec2 center,
           std::string filepath, glm::vec4 col);
    ~Sprite();
    void  visitSelf() override;


private:

    std::shared_ptr<Shader> _shader;
    std::string  _filepath;
    unsigned int quadVAO;
    void initRenderData();
};

#endif //ZUMA_SPRITE_H
