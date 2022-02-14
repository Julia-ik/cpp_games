//
// Created by lilu on 09/02/2022.
//

#include "ImguiShader.h"
#include <string>
namespace
{
    constexpr auto vs_program =
            R"(
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

    constexpr auto ps_program =
            R"(
#version 330 core

uniform sampler2D uTexture;

in vec2 oTexCoord;
in vec4 oColor;
out vec4 color;

void main()
{
    color = texture(uTexture, oTexCoord)* oColor;
}
)";
}

ImguiShader::ImguiShader()
        : Shader({"position", "texCoord", "color"},vs_program, ps_program)
{
}