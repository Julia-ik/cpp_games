//
// Created by lilu on 30.11.2021.
//

#include "Shader.h"
#include <string>
#define GLEW_NO_GLU
#include <GL/glew.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Uniforms.h"

Shader::Shader(GLuint programID){
    this->programID = programID;
}
Shader::Shader()
{
    GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint FragmentShaderID =glCreateShader(GL_FRAGMENT_SHADER);


    std::string VertexShaderCode =R"(
#version 330 core

layout (location = 0) in vec2 position;
layout (location = 1) in vec2 texCoord;
layout (location = 2) in vec4 color;

out vec2 oTexCoord;
out vec4 oColor;

uniform vec2 uScreenSize;
uniform mat3 uTransform;

void main()
{
    oColor = color;

    vec2 pos = (uTransform * vec3(position, 1.0)).xy;
    vec2 scaledPos = pos / uScreenSize;
    scaledPos.y = 1.0 - scaledPos.y;
    scaledPos = scaledPos * 2.0 - vec2(1.0);

    oTexCoord = texCoord;
    gl_Position = vec4(scaledPos.x, scaledPos.y, 1.0, 1.0);
}
)";

    std::string FragmentShaderCode = R"(
#version 330 core

uniform sampler2D uTexture;

in vec2 oTexCoord;
in vec4 oColor;
out vec4 color;

void main()
{
    color = texture(uTexture, oTexCoord) * oColor;
}
)";



    GLint Result = GL_FALSE;
    int InfoLogLength;

// Компилируем Вершинный шейдер
    char const * VertexSourcePointer = VertexShaderCode.c_str();
    glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
    glCompileShader(VertexShaderID);

// Выполняем проверку Вершинного шейдера
    glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if ( InfoLogLength > 0 )
    {
        std::vector<char> VertexShaderErrorMessage(InfoLogLength+1);
        glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
        fprintf(stdout, "%sn", &VertexShaderErrorMessage[0]);
    }

// Компилируем Фрагментный шейдер
    char const * FragmentSourcePointer = FragmentShaderCode.c_str();
    glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL);
    glCompileShader(FragmentShaderID);

// Проверяем Фрагментный шейдер
    glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if ( InfoLogLength > 0 )
    {
        std::vector<char> FragmentShaderErrorMessage(InfoLogLength+1);
        glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
        fprintf(stdout, "%s\n", &FragmentShaderErrorMessage[0]);
    }


// Создаем шейдерную программу и привязываем шейдеры к ней
    fprintf(stdout, "creating shader program");


    programID = glCreateProgram();
    glAttachShader(programID, VertexShaderID);
    glAttachShader(programID, FragmentShaderID);
    glLinkProgram(programID);

// Проверяем шейдерную программу
    glGetProgramiv(programID, GL_LINK_STATUS, &Result);
    glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if ( InfoLogLength > 0 )
    {
        std::vector<char> ProgramErrorMessage(InfoLogLength+1);
        glGetProgramInfoLog(programID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
        fprintf(stdout, "%s\n", &ProgramErrorMessage[0]);
    }

    glDeleteShader(VertexShaderID);
    glDeleteShader(FragmentShaderID);
}

void Shader::Use()
{
    glUseProgram(programID);
}

std::shared_ptr<GlTextureUniform> Shader::createTextureUniform(std::string_view name, std::shared_ptr<Shader> & shader)
{
    return std::make_shared<GlTextureUniform>(shader, name);
}

std::shared_ptr<GlMat3Uniform> Shader::createMat3Uniform(std::string_view name, std::shared_ptr<Shader> & shader)
{
    return std::make_shared<GlMat3Uniform>(shader, name);
}

std::shared_ptr<GlVec2Uniform> Shader::createVec2Uniform(std::string_view name, std::shared_ptr<Shader> & shader)
{
    return std::make_shared<GlVec2Uniform>(shader, name);
}

void GlMat3Uniform::activate()
{
    glUniformMatrix3fv(_location, 1, GL_FALSE, glm::value_ptr(value));
}

GlVec2Uniform::GlVec2Uniform(const std::shared_ptr<Shader> &program, std::string_view name)
{
    _location = glGetUniformLocation(program->programID, name.data());
}

void GlVec2Uniform::activate()
{
    glUniform2f(_location, value.x, value.y);
}


void GlTextureUniform::activate()
{
    auto glTexture = std::dynamic_pointer_cast<Texture>(texture);
    if (glTexture)
    {
        //TODO: diff texture slots
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, glTexture->ID);

        glUniform1i(_location, 0);
    }
}

