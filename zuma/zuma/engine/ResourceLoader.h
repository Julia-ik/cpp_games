//
// Created by lilu on 16/01/2022.
//

#ifndef ZUMA_RESOURCELOADER_H
#define ZUMA_RESOURCELOADER_H

#include <map>
#include <string>
#include "Shader.h"
#include "Texture.h"
//#include "Sound.h"

class ResourceManager
{
public:
    static std::map<std::string, Shader> Shaders;
    static Shader LoadShader(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile, std::string name);
    //static Shader LoadShader(GLuint program, std::string name);
    static Shader GetShader(std::string name);
    static void Clear();
private:
      ResourceManager() { }
    static Shader loadShaderFromFile(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile = nullptr);
    static Texture loadTextureFromFile(std::string_view filepath, bool alpha);

};
#endif //ZUMA_RESOURCELOADER_H
