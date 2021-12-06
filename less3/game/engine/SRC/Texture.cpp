//
// Created by lilu on 04.12.2021.
//

#include "Texture.h"
#include "GL/gl.h"
#include <vector>



Texture::Texture()
        : Width(0), Height(0), Internal_Format(GL_RGB), Image_Format(GL_RGB), Wrap_S(GL_REPEAT), Wrap_T(GL_REPEAT), Filter_Min(GL_LINEAR), Filter_Max(GL_LINEAR)
{
    glGenTextures(1, &this->ID);
}

void Texture::Generate(Bitmap bitmap)
{
    const auto glInternalFormat = getGlInternalFormat(bitmap.getFormat());
    const auto glType = getGlType(bitmap.getFormat());
    const auto glFormat = getGlFormat(bitmap.getFormat());

    // Создаем текстуру
    glBindTexture(GL_TEXTURE_2D, this->ID);
    glTexImage2D(GL_TEXTURE_2D, 0, glInternalFormat, bitmap.getSize().x,
                 bitmap.getSize().y, 0, glFormat, glType, bitmap.getImage().data());

    // Задаем для текстуры режимы наложения и фильтрации
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, this->Wrap_S);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, this->Wrap_T);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->Filter_Min);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->Filter_Max);

    // Отвязываем текстуру
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::Bind() const
{
    glBindTexture(GL_TEXTURE_2D, this->ID);
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