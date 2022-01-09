//
// Created by lilu on 04.12.2021.
//

#ifndef GAME_TEXTURE_H
#define GAME_TEXTURE_H
#include <vector>
#include "Bitmap.h"


class Texture {
public:
    // Содержит ID объекта текстуры, используемый для всех операций с конкретной текстурой
    unsigned int ID;

    // Конструктор (устанавливает заданные по умолчанию значения)
    Texture(Bitmap bitmap);


    // Связываем текстуру в виде текущего активного GL_TEXTURE_2D текстурного объекта
    void Bind();

    unsigned int getGlType(Bitmap::Format bitmapFormat);

    unsigned int getGlFormat(Bitmap::Format bitmapFormat);

    unsigned int getGlInternalFormat(Bitmap::Format bitmapFormat);
};


#endif //GAME_TEXTURE_H
