//
// Created by lilu on 14/12/2021.
//

#ifndef GAME_SHADERS_H
#define GAME_SHADERS_H
#include <string>

std::string vertexShader = "#version 330 core\n"
                           "layout (location = 0) in vec4 vertex;\n"
                           " \n"
                           "out vec2 TexCoords;\n"
                           " \n"
                           "uniform mat4 model;\n"
                           "uniform mat4 projection;\n"
                           " \n"
                           "void main()\n"
                           "{\n"
                           "    TexCoords = vertex.zw;\n"
                           "    gl_Position = projection * model * vec4(vertex.xy, 0.0, 1.0);\n"
                           "}";

std::string fragmentShaderWithColor = "#version 330 core\n"
                             "in vec2 TexCoords;\n"
                             "out vec4 color;\n"
                             " \n"
                             "uniform sampler2D image;\n"
                             "uniform vec3 spriteColor;\n"
                             " \n"
                             "void main()\n"
                             "{    \n"
                             "    color = vec4(spriteColor, 1.0) * texture(image, TexCoords);\n"
                             "}  ";

std::string fragmentShader = "#version 330 core\n"
                             "in vec2 TexCoords;\n"
                             "out vec4 color;\n"
                             " \n"
                             "uniform sampler2D image;\n"
                             "uniform vec3 spriteColor;\n"
                             " \n"
                             "void main()\n"
                             "{    \n"
                             "    color = texture(image, TexCoords);\n"
                             "}  ";

#endif //GAME_SHADERS_H
