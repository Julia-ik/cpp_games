//
// Created by lilu on 04.12.2021.
//

#include "Texture.h"
#include "GL/gl.h"
#include <vector>
#include <GLES2/gl2.h>


Texture::Texture(Bitmap bitmap)
{
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);

    const auto glInternalFormat = getGlInternalFormat(bitmap.getFormat());
    const auto glType = getGlType(bitmap.getFormat());
    const auto glFormat = getGlFormat(bitmap.getFormat());

    auto dd = bitmap.getImage().data();

    glTexImage2D(GL_TEXTURE_2D, 0, glInternalFormat, bitmap.getSize().x, bitmap.getSize().y, 0,
                 glFormat, glType, bitmap.getImage().data());


    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

    glGenerateMipmap(GL_TEXTURE_2D);
}


void Texture::Bind()
{
    glBindTexture(GL_TEXTURE_2D, ID);
}

GLenum Texture::getGlInternalFormat(Bitmap::Format bitmapFormat){
    if (bitmapFormat == Bitmap::Format::R)
    {
        return GL_R8;
    }

    if (bitmapFormat == Bitmap::Format::Rgba32F || bitmapFormat == Bitmap::Format::Rgb32F)
    {
        return GL_RGBA32F;
    }
    else if (bitmapFormat == Bitmap::Format::Rgba16F)
    {
        return GL_RGBA16F;
    }
    else if (bitmapFormat == Bitmap::Format::Rgb16F)
    {
        return GL_RGB16F;
    }
    else if (bitmapFormat == Bitmap::Format::Rgb)
    {
        return GL_RGB;
    }
    else
    {
        return GL_RGBA;
    }
}

GLenum Texture::getGlFormat(Bitmap::Format bitmapFormat)
{
    switch (bitmapFormat)
    {
        case Bitmap::Format::R:
            return GL_RED;

        case Bitmap::Format::Rgb:
        case Bitmap::Format::Rgb16F:
        case Bitmap::Format::Rgb32F:
            return GL_RGB;

        case Bitmap::Format::Rgba:
        case Bitmap::Format::Rgba16F:
        case Bitmap::Format::Rgba32F:
            return GL_RGBA;

    }
}

GLenum Texture::getGlType(Bitmap::Format bitmapFormat)
{
    switch (bitmapFormat)
    {
        case Bitmap::Format::Rgb32F:
        case Bitmap::Format::Rgba32F:
            return GL_FLOAT;

        case Bitmap::Format::Rgb16F:
        case Bitmap::Format::Rgba16F:
            return GL_HALF_FLOAT;

        case Bitmap::Format::Rgb:
        case Bitmap::Format::Rgba:
        case Bitmap::Format::R:
            return GL_UNSIGNED_BYTE;

    }
}