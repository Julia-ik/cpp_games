//
// Created by lilu on 04.12.2021.
//

#ifndef GAME_TEXTURE_H
#define GAME_TEXTURE_H
#include <vector>
#include "../Bitmap.h"


class Texture {
public:
    // Содержит ID объекта текстуры, используемый для всех операций с конкретной текстурой
    unsigned int ID;

    // Размеры текстурного изображения
    unsigned int Width, Height; // ширина и высота (в пикселях) загруженного изображения

    // Формат текстуры
    unsigned int Internal_Format; // внутренний формат текстуры
    unsigned int Image_Format; // формат загружаемого изображения

    // Конфигурация текстуры
    unsigned int Wrap_S; // режим наложения по оси S
    unsigned int Wrap_T; // режим наложения по оси T
    unsigned int Filter_Min; // режим фильтрации, если пикселей текстуры < пикселей экрана
    unsigned int Filter_Max; // режим фильтрации, если пикселей текстуры > пикселей экрана

    // Конструктор (устанавливает заданные по умолчанию значения)
    Texture();

    // Генерируем текстуру из изображения
    void Generate(Bitmap bitmap );

    // Связываем текстуру в виде текущего активного GL_TEXTURE_2D текстурного объекта
    void Bind() const;

    unsigned int getGlType(Bitmap::Format bitmapFormat);

    unsigned int getGlFormat(Bitmap::Format bitmapFormat);

    unsigned int getGlInternalFormat(Bitmap::Format bitmapFormat);
};


#endif //GAME_TEXTURE_H
