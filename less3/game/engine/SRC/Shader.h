//
// Created by lilu on 30.11.2021.
//

#ifndef GAME_SHADER_H
#define GAME_SHADER_H
#define GLEW_NO_GLU
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/detail/type_vec2.hpp>
#include <memory>
#include <optional>
#include <string_view>
#include "Texture.h"


class GlTextureUniform;
class GlMat3Uniform;
class GlVec2Uniform;

class Shader
{
public:
Shader();

Shader(GLuint programID);

void Use();
GLuint programID;


std::shared_ptr<GlTextureUniform> createTextureUniform(std::basic_string_view<char> name, std::shared_ptr<Shader>& program);

std::shared_ptr<GlMat3Uniform> createMat3Uniform(std::string_view name, std::shared_ptr<Shader>& program);

std::shared_ptr<GlVec2Uniform> createVec2Uniform(std::string_view name, std::shared_ptr<Shader>& program);
};






#endif //GAME_SHADER_H
