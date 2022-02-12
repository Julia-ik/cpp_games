//
// Created by lilu on 09/02/2022.
//

#include "SpriteShader.h"
#include <string>
namespace
{
    constexpr auto vs_program =
            R"(
VS_IN vec2 position;
VS_IN vec2 texCoord;
VS_IN vec4 color;

VS_OUT vec2 oTexCoord;
VS_OUT vec4 oColor;

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
uniform sampler2D uTexture;

PS_IN vec2 oTexCoord;
PS_IN vec4 oColor;

void main()
{
    PS_OUT = TEXTURE2D(uTexture, oTexCoord) * oColor;
}
)";
}

SpriteShader::SpriteShader()
        : Shader({"position", "texCoord", "color"},vs_program, ps_program)
{
}