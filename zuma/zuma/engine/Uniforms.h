//
// Created by lilu on 16/01/2022.
//

#ifndef ZUMA_UNIFORMS_H
#define ZUMA_UNIFORMS_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/detail/type_vec2.hpp>
#include <memory>
#include "Shader.h"
#include "Texture.h"


class GlTextureUniform
{
public:
    GlTextureUniform(const std::shared_ptr<Shader>& program, std::string_view name);
    void activate();
    std::shared_ptr<Texture> texture;

private:
    int32_t _location;
};

class GlMat3Uniform
{
public:
    GlMat3Uniform(const std::shared_ptr<Shader>& program, std::string_view name);
    void activate();
    glm::mat3 value;

private:
    int32_t _location;
};

class GlVec2Uniform
{
public:
    GlVec2Uniform(const std::shared_ptr<Shader>& program, std::string_view name);
    void activate();
    glm::vec2 value;

private:
    int32_t _location;
};



#endif //ZUMA_UNIFORMS_H
