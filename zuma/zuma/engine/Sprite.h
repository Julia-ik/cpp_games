//
// Created by lilu on 16/01/2022.
//

#ifndef ZUMA_SPRITE_H
#define ZUMA_SPRITE_H

#include "Texture.h"
#include "Node.h"
//#include "Color.h"
#include "Shader.h"
#include <string>
#include "Bitmap.h"
#include "Renderer.h"
#include "ResourceLoader.h"
#include "MeshData.h"
#include "Engine.h"

class Sprite: public Node
{
public:
    MeshData meshData;
    const Engine &_engine;
    Renderer::Command _command;

    std::shared_ptr<GlVec2Uniform> _screenSizeUniform;
    std::shared_ptr<GlMat3Uniform>  _transformUniform;
    std::shared_ptr<GlTextureUniform>  _textureUniform;

    Sprite(const Engine &_engine, const Shader &shader, glm::vec2 position, glm::vec2 size, float rotation, glm::vec2 center,
           std::string filepath);
    ~Sprite();
    void  visitSelf() override;
    //glm::vec4 _color;

private:

    Shader shader;
    std::string  _filepath;
    unsigned int quadVAO;
    void initRenderData();
};

#endif //ZUMA_SPRITE_H
