//
// Created by lilu on 16/01/2022.
//

#include "Renderer.h"
#include "VertexBuffer.h"
#include <glm/gtc/type_ptr.hpp>
#include "Engine.h"
#include "Uniforms.h"
#include "ResourceLoader.h"
#include <SDL.h>


Renderer::Renderer(const Engine &engine) :_engine(engine)
        , _drawContext{SDL_GL_CreateContext(engine.window), SDL_GL_DeleteContext}
{
    printf("OpenGL version supported by this platform (%s): \n",
           glGetString(GL_VERSION));

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Renderer::draw()
{
    auto needRender = [](uint32_t renderMask, uint32_t nodeMask)
    {
        return (renderMask == nodeMask) || (nodeMask & renderMask) != 0;
    };

    glDisable(GL_SCISSOR_TEST);
    //glClearColor(0.0f, 0.3f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_SCISSOR_TEST);
    for (const auto &command: _commands)
    {
        auto spriteVertexBuffer = std::dynamic_pointer_cast<VertexBuffer>(command.vertexBuffer);
        auto particleBuffer = std::dynamic_pointer_cast<ParticleBuffer>(
                command.vertexBuffer);

        if (spriteVertexBuffer || particleBuffer)
        {
            auto glProgram = std::dynamic_pointer_cast<Shader>(command.program);

            if (glProgram)
            {
                glProgram->Use();
                if(command._screenSizeUniform)
                {
                    command._screenSizeUniform->activate();
                }
                if(command._textureUniform)
                {
                    command._textureUniform->activate();
                }
                if(command._colorUniform)
                {
                    command._colorUniform->activate();
                }
                if(command._transformUniform)
                {
                    command._transformUniform->activate();
                }
                if(command._timeUniform)
                {
                    command._timeUniform->activate();
                }
                if(command._resolutionUniform)
                {
                    command._resolutionUniform->activate();
                }

                if (command.scissor)
                {
                    glScissor((int) command.scissor->x,
                              (int) (_engine.heights - command.scissor->w),
                              (int) (command.scissor->z - command.scissor->x),
                              (int) (command.scissor->w - command.scissor->y));
                }
                else
                {
                    glScissor(0, 0, _engine.width, _engine.heights);
                }

                if(spriteVertexBuffer)
                {
                    if (command.sub)
                    {
                        spriteVertexBuffer->draw(command.sub->num, command.sub->offset);
                    }
                    else
                    {
                        spriteVertexBuffer->draw();
                    }
                }
                if (particleBuffer)
                {
                    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
                    particleBuffer->draw();
                    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                }

            }
        }
    }
    _commands.clear();
}


std::shared_ptr<BaseVertexBuffer> Renderer::createVertexBuffer(MeshData data) const
{
    return _engine.createShared<VertexBuffer>(data);
}

std::shared_ptr<Shader> Renderer::createProgram(std::string_view name) const
{
    std::string name_string(name);
    auto shader = _engine._resManager->GetShader(name_string);

    return shader;
}

std::shared_ptr<Texture> Renderer::createTexture(Bitmap bitmap) const
{
    return _engine.createShared<Texture>(std::move(bitmap));
}

glm::vec2 Renderer::getRenderResolution()
{
    GLint curViewport[4];
    glGetIntegerv(GL_VIEWPORT, curViewport);
    return glm::vec2(curViewport[2], curViewport[3]);
}

std::shared_ptr<ParticleBuffer> Renderer::createParticleBuffer(std::vector<ParticleBuffer::ParticleData> data) const
{
    return _engine.createShared<ParticleBuffer>(std::move(data));
}

std::shared_ptr<ParticleBuffer> Renderer::createParticleBuffer(size_t count) const
{
    return _engine.createShared<ParticleBuffer>(count);
}
