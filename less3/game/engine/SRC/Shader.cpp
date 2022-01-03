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

Shader::Shader(GLuint programID){
    this->programID = programID;
}
Shader::Shader()
{
    GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint FragmentShaderID =glCreateShader(GL_FRAGMENT_SHADER);


    std::string VertexShaderCode ="#version 330 core\n"
                                  "layout (location = 0) in vec2 position;\n"
                                  "layout (location = 1) in vec2 textureCoords;\n"
                                  //"layout (location = 2) in vec4 color;\n"
                                  "out vec2 TexCoords;\n"
                                  //"out vec4 color_f; "
                                  " \n"
                                  "uniform mat4 model;\n"
                                  "uniform mat4 projection;\n"
                                  " \n"
                                  "void main()\n"
                                  "{\n"
                                  "    TexCoords = textureCoords;\n"
                                  //"     color_f = color;"
                                  "    gl_Position = projection * model * vec4(position, 0.0, 1.0);\n"
                                  "}";

    std::string FragmentShaderCode = "#version 330 core\n"
                                     "in vec2 TexCoords;\n"
                                     "out vec4 color;\n"
                                     //"in vec4 color_f;"
                                     " \n"
                                     "uniform sampler2D image;\n"
                                     "uniform vec4 spriteColor;\n"
                                     " \n"
                                     "void main()\n"
                                     "{    \n"
                                     "    color = texture(image, TexCoords);\n"
                                     "}  ";



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

    uScreenSize = glGetUniformLocation(programID, "screenSize");

//return ProgramID;
}

Shader &Shader::Use()
{
    glUseProgram(this->programID);
    return *this;
}

void Shader::SetFloat(const char *name, float value, bool useShader)
{
    if (useShader)
        this->Use();
    glUniform1f(glGetUniformLocation(this->programID, name), value);
}
void Shader::SetInteger(const char *name, int value, bool useShader)
{
    if (useShader)
        this->Use();
    glUniform1i(glGetUniformLocation(this->programID, name), value);
}
void Shader::SetVector2f(const char *name, float x, float y, bool useShader)
{
    if (useShader)
        this->Use();
    glUniform2f(glGetUniformLocation(this->programID, name), x, y);
}
void Shader::SetVector2f(const char *name, const glm::vec2 &value, bool useShader)
{
    if (useShader)
        this->Use();
    glUniform2f(glGetUniformLocation(this->programID, name), value.x, value.y);
}
void Shader::SetVector3f(const char *name, float x, float y, float z, bool useShader)
{
    if (useShader)
        this->Use();
    glUniform3f(glGetUniformLocation(this->programID, name), x, y, z);
}
void Shader::SetVector3f(const char *name, const glm::vec3 &value, bool useShader)
{
    if (useShader)
        this->Use();
    glUniform3f(glGetUniformLocation(this->programID, name), value.x, value.y, value.z);
}
void Shader::SetVector4f(const char *name, float x, float y, float z, float w, bool useShader)
{
    if (useShader)
        this->Use();
    glUniform4f(glGetUniformLocation(this->programID, name), x, y, z, w);
}
void Shader::SetVector4f(const char *name, const glm::vec4 &value, bool useShader)
{
    if (useShader)
        this->Use();
    glUniform4f(glGetUniformLocation(this->programID, name), value.x, value.y, value.z, value.w);
}
void Shader::SetMatrix4(const char *name, const glm::mat4 &matrix, bool useShader)
{
    if (useShader)
        this->Use();
    glUniformMatrix4fv(glGetUniformLocation(this->programID, name), 1, false, glm::value_ptr(matrix));
}
