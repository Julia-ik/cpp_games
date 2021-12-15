//
// Created by lilu on 04.12.2021.
//

#ifndef GAME_RESOURCELOADER_H
#define GAME_RESOURCELOADER_H

#include <map>
#include <string>
#include "Texture.h"
#include "Shader.h"
#include "Sound.h"

// Статический одноэлементный класс ResourceManager, содержащий несколько функций для загрузки текстур и шейдеров.
// Каждая загруженная текстура и/или шейдер сохраняются для дальнейшего использования.
// Все функции и ресурсы статичны
class ResourceManager
{
public:

    // Хранилище ресурсов
    static std::map<std::string, Shader> Shaders;
    static std::map<std::string, Texture> Textures;

    // Загружаем (и генерируем) шейдерную программу из файла загрузки исходного кода вершинных, фрагментных (и геометрических) шейдеров.
    // Если gShaderFile != nullptr, то также загружается и геометрический шейдер
    static Shader LoadShader(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile, std::string name);
    //static Shader LoadShader(GLuint program, std::string name);
    // Получаем сохраненный шейдер
    static Shader GetShader(std::string name);

    // Загружаем (и генерируем) текстуру из файла
    static Texture LoadTexture(std::string_view file, bool alpha, std::string name);

    // Получаем сохраненную текстуру
    static Texture GetTexture(std::string name);

    // Корректное освобождение памяти всех загруженных ресурсов
    static void Clear();
private:
    // private-конструктор, т.к. мы не хотим, чтобы создавались реальные объекты менеджера ресурсов. Его члены и функции должны быть общедоступными (статичными)
    ResourceManager() { }

    // Загружаем и генерируем шейдер из файла
    static Shader loadShaderFromFile(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile = nullptr);

    // Загружаем текстуру из файла
    static Texture loadTextureFromFile(std::string_view filepath, bool alpha);


};


#endif //GAME_RESOURCELOADER_H
