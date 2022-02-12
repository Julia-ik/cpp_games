//
// Created by lilu on 16/01/2022.
//

#ifndef ZUMA_UNIFORMS_H
#define ZUMA_UNIFORMS_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/detail/type_vec2.hpp>
#include <memory>
#include <functional>
#include "Shader.h"
#include "Texture.h"

class Uniform
{
protected:
    virtual void activate()
    {
        if (onActivate)
        {
            onActivate();
        }
    }

public:
    std::function<void(void)> onActivate;
};

class GlVec3Uniform :public Uniform
{
public:
    GlVec3Uniform(const std::shared_ptr<Shader>& program, std::string_view name);
    void activate() override;
    glm::vec3 value;
private:
    int32_t _location;

};

class GlFloatUniform :public Uniform
{
public:
    GlFloatUniform(const std::shared_ptr<Shader>& program, std::string_view name);
    void activate() override;
    float value;
private:
    int32_t _location;

};

class GlTextureUniform :public Uniform
{
public:
    GlTextureUniform(const std::shared_ptr<Shader>& program, std::string_view name);
    void activate() override;
    std::shared_ptr<Texture> texture;

private:
    int32_t _location;
};

class GlMat3Uniform :public Uniform
{
public:
    GlMat3Uniform(const std::shared_ptr<Shader>& program, std::string_view name);
    void activate() override;
    glm::mat3 value;

private:
    int32_t _location;
};

class GlVec2Uniform :public Uniform
{
public:
    GlVec2Uniform(const std::shared_ptr<Shader>& program, std::string_view name);
    void activate() override;
    glm::vec2 value;

private:
    int32_t _location;
};



#endif //ZUMA_UNIFORMS_H
