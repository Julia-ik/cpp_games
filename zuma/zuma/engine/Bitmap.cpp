//
// Created by lilu on 16/01/2022.
//

#include "Bitmap.h"

#include "Bitmap.h"
#define STB_IMAGE_IMPLEMENTATION
#include <string>
#include <SDL.h>
#include "stb_image.h"
#include <stdexcept>

Bitmap::Bitmap(std::string_view filepath)
{
    SDL_RWops *file = SDL_RWFromFile(filepath.data(), "rb");
    //SDL_RWops *file = SDL_RWFromFile(_fileManager.resourceLocation(std::string{filepath}).c_str(), "rb");
    if (file == nullptr)
    {
        throw std::runtime_error("Failed to open file: " + std::string{filepath});
    }

    Sint64 length = SDL_RWsize(file);
    std::vector<unsigned char> data(length);

    SDL_RWread(file, data.data(), length, 1);
    SDL_RWclose(file);


    int width, height, ch;
    stbi_set_flip_vertically_on_load(false);
    auto img = stbi_load_from_memory(data.data(), data.size(), &width, &height, &ch, 0);
    if (img == nullptr)
    {
        throw std::runtime_error("unsupported file format: " + std::string{filepath});
    }

    auto getFmt = [](int ch)
    {
        switch (ch)
        {
            case 1:
                return Format::R;
            case 3:
                return Format::Rgb;
            case 4:
                return Format::Rgba;

            default:
                throw std::invalid_argument("Incorect chanels size from TGA");
        }
    };

    _format = getFmt(ch);
    auto imgSize = width*height*ch;

    //TODO: no copy
    _image = {img, img + imgSize};

    _size = glm::vec2(width, height);

    stbi_image_free(img);
}

const std::vector<unsigned char>& Bitmap::getImage() const
{
    return _image;
}

Bitmap::Format Bitmap::getFormat() const
{
    return _format;
}

glm::vec2 Bitmap::getSize() const
{
    return _size;
}

Bitmap::Bitmap(Format format, std::vector<unsigned char> image,glm::vec2 size)
        :_format(format),_image(std::move(image)), _size(size)
{}
