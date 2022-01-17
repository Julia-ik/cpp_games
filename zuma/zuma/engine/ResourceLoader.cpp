
//
// Created by lilu on 16/01/2022.
//

#include "ResourceLoader.h"
#include "Bitmap.h"
#include "stb_image.h"

std::map<std::string, Shader> ResourceManager::Shaders;


Shader ResourceManager::LoadShader(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile, std::string name)
{

    Shaders[name] = loadShaderFromFile(vShaderFile, fShaderFile, gShaderFile);
    return Shaders[name];
}


Shader ResourceManager::GetShader(std::string name)
{

    return Shaders[name];

}


void ResourceManager::Clear()
{
    for (auto iter : Shaders)
        glDeleteProgram(iter.second.programID);
}

Shader ResourceManager::loadShaderFromFile(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile)
{
    Shader shader;
    return shader;
}