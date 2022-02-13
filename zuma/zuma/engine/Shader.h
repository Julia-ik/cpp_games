//
// Created by lilu on 16/01/2022.
//

#ifndef ZUMA_SHADER_H
#define ZUMA_SHADER_H

#define GLEW_NO_GLU
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/detail/type_vec2.hpp>
#include <memory>
#include <optional>
#include <string_view>


class GlTextureUniform;
class GlMat3Uniform;
class GlVec2Uniform;
class GlVec3Uniform;
class GlVec4Uniform;
class GlFloatUniform;

class Shader
{
public:
    Shader(std::initializer_list<const char*> attributes, std::string vs, std::string ps);

    Shader(GLuint programID);

    void Use();
    GLuint programID;

    std::shared_ptr<GlTextureUniform> createTextureUniform(std::basic_string_view<char> name, std::shared_ptr<Shader>& program);

    std::shared_ptr<GlMat3Uniform> createMat3Uniform(std::string_view name, std::shared_ptr<Shader>& program);

    std::shared_ptr<GlVec2Uniform> createVec2Uniform(std::string_view name, std::shared_ptr<Shader>& program);


    std::shared_ptr<GlVec3Uniform> createVec3Uniform(std::string_view name, std::shared_ptr<Shader>& program);
    std::shared_ptr<GlVec4Uniform> createVec4Uniform(std::string_view name, std::shared_ptr<Shader>& program);
    std::shared_ptr<GlFloatUniform> createFloatUniform(std::string_view name, std::shared_ptr<Shader>& program);
};








#endif //ZUMA_SHADER_H
