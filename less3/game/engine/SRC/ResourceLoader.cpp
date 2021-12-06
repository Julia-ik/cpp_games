//
// Created by lilu on 04.12.2021.
//

#include "ResourceLoader.h"
#include "Bitmap.h"

#include "stb_image.h"

// Создание экземпляров статических переменных
std::map<std::string, Texture> ResourceManager::Textures;
std::map<std::string, Shader> ResourceManager::Shaders;


Shader ResourceManager::LoadShader(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile, std::string name)
{
    
    Shaders[name] = loadShaderFromFile(vShaderFile, fShaderFile, gShaderFile);
    return Shaders[name];
}

/*Shader ResourceManager::LoadShader(GLuint program, std::string name)
{
    Shader shader(program);
    Shaders[name]=shader;
    return Shaders[name];
}*/

Shader ResourceManager::GetShader(std::string name)
{
    return Shaders[name];
}

Texture ResourceManager::LoadTexture(std::string_view file, bool alpha, std::string name)
{
    Textures[name] = loadTextureFromFile(file, alpha);
    return Textures[name];
}

Texture ResourceManager::GetTexture(std::string name)
{
    return Textures[name];
}

void ResourceManager::Clear()
{
    // (корректное) удаление всех шейдеров
    for (auto iter : Shaders)
        glDeleteProgram(iter.second.programID);

    // (корректное) удаление всех текстур
    for (auto iter : Textures)
        glDeleteTextures(1, &iter.second.ID);
}

Shader ResourceManager::loadShaderFromFile(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile)
{

    Shader shader;

    return shader;
}

Texture ResourceManager::loadTextureFromFile(std::string_view filepath, bool alpha)
{
    // Создаем объект текстуры
    Texture texture;
    if (alpha)
    {
        texture.Internal_Format = GL_RGB;
        texture.Image_Format = GL_RGB;
    }

    // Загружаем изображение
    int width, height, nrChannels;
    Bitmap bitmap(filepath);


    // Теперь генерируем текстуру
    texture.Generate(bitmap);


    return texture;
}