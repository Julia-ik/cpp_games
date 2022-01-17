//
// Created by lilu on 16/01/2022.
//

#ifndef ZUMA_BITMAP_H
#define ZUMA_BITMAP_H

#include <string_view>
#include <vector>
#include <glm/glm.hpp>

class Bitmap
{
public:
    enum class Format
    {
        R,
        Rgb,
        Rgba,
        Rgba16F,
        Rgba32F,
        Rgb16F,
        Rgb32F,
    };

    explicit Bitmap(std::string_view filepath);
    Bitmap(Format format, std::vector<unsigned char> image,glm::vec2 size);

    const std::vector<unsigned char>& getImage() const;

    Format getFormat() const;
    glm::vec2 getSize() const;

private:
    Format _format;
    std::vector<unsigned char> _image;
    glm::vec2 _size;
};


#endif //ZUMA_BITMAP_H
