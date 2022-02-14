//
// Created by lilu on 16/01/2022.
//

#include "Shader.h"
#include <string>
#define GLEW_NO_GLU
#include <GL/glew.h>
#include <vector>
#include <glm/gtc/type_ptr.hpp>
#include "Uniforms.h"


Shader::Shader(GLuint programID){
    this->programID = programID;
}
Shader::Shader(std::initializer_list<const char*> attributes, std::string vs, std::string ps)
{
    GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint FragmentShaderID =glCreateShader(GL_FRAGMENT_SHADER);

    GLint Result = GL_FALSE;
    int InfoLogLength;

    char const * VertexSourcePointer = vs.c_str();
    glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
    glCompileShader(VertexShaderID);

    glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if ( InfoLogLength > 0 )
    {
        std::vector<char> VertexShaderErrorMessage(InfoLogLength+1);
        glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
        fprintf(stdout, "%sn", &VertexShaderErrorMessage[0]);
    }

    char const * FragmentSourcePointer = ps.c_str();
    glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL);
    glCompileShader(FragmentShaderID);


    glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if ( InfoLogLength > 0 )
    {
        std::vector<char> FragmentShaderErrorMessage(InfoLogLength+1);
        glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
        fprintf(stdout, "%s\n", &FragmentShaderErrorMessage[0]);
    }

    fprintf(stdout, "\n Creating shader program \n");


    programID = glCreateProgram();

    size_t index = 0;
    for (auto attribute : attributes)
    {
        glBindAttribLocation(programID, index++, attribute);
    }
    glAttachShader(programID, VertexShaderID);
    glAttachShader(programID, FragmentShaderID);
    glLinkProgram(programID);

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
std::shared_ptr<GlVec3Uniform> Shader::createVec3Uniform(std::string_view name, std::shared_ptr<Shader> & shader)
{
    return std::make_shared<GlVec3Uniform>(shader, name);
}

std::shared_ptr<GlVec4Uniform> Shader::createVec4Uniform(std::string_view name, std::shared_ptr<Shader> & shader)
{
    return std::make_shared<GlVec4Uniform>(shader, name);
}

std::shared_ptr<GlFloatUniform> Shader::createFloatUniform(std::string_view name, std::shared_ptr<Shader> & shader)
{
    return std::make_shared<GlFloatUniform>(shader, name);
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



GlVec3Uniform::GlVec3Uniform(const std::shared_ptr<Shader> &program, std::string_view name)
{
    _location = glGetUniformLocation(program->programID, name.data());
}

void GlVec3Uniform::activate()
{
    Uniform::activate();
    glUniform3f(_location, value.x, value.y, value.z);
}

GlVec4Uniform::GlVec4Uniform(const std::shared_ptr<Shader> &program, std::string_view name)
{
    _location = glGetUniformLocation(program->programID, name.data());
}

void GlVec4Uniform::activate()
{
    Uniform::activate();
    glUniform4f(_location, value.x, value.y, value.z, 1.0f);
}

GlVec2Uniform::GlVec2Uniform(const std::shared_ptr<Shader> &program, std::string_view name)
{
    _location = glGetUniformLocation(program->programID, name.data());
}
void GlVec2Uniform::activate()
{
    Uniform::activate();
    glUniform2f(_location, value.x, value.y);
}

GlTextureUniform::GlTextureUniform(const std::shared_ptr<Shader>& program, std::string_view name)
{
    _location = glGetUniformLocation(program->programID, name.data());
}

void GlTextureUniform::activate()
{
    Uniform::activate();
    auto glTexture = std::dynamic_pointer_cast<Texture>(texture);
    if (glTexture)
    {
        //TODO: diff texture slots
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, glTexture->ID);

        glUniform1i(_location, 0);
    }
}
GlMat3Uniform::GlMat3Uniform(const std::shared_ptr<Shader> &program, std::string_view name)
{
    _location = glGetUniformLocation(program->programID, name.data());
}
void GlMat3Uniform::activate()
{
    Uniform::activate();
    glUniformMatrix3fv(_location, 1, GL_FALSE, glm::value_ptr(value));
}

GlFloatUniform::GlFloatUniform(const std::shared_ptr<Shader> &program, std::string_view name)
{
    _location = glGetUniformLocation(program->programID, name.data());
}

void GlFloatUniform::activate()
{
    Uniform::activate();
    glUniform1f(_location, value);
}
