//
// Created by lilu on 16/01/2022.
//

#ifndef ZUMA_TEXTURE_H
#define ZUMA_TEXTURE_H


#include "Bitmap.h"

class Texture
{
public:
    unsigned int ID;
    Texture(Bitmap bitmap);


    void Bind();

    unsigned int getGlType(Bitmap::Format bitmapFormat);

    unsigned int getGlFormat(Bitmap::Format bitmapFormat);

    unsigned int getGlInternalFormat(Bitmap::Format bitmapFormat);
};

#endif //ZUMA_TEXTURE_H
