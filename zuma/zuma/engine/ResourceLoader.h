//
// Created by lilu on 16/01/2022.
//

#ifndef ZUMA_RESOURCELOADER_H
#define ZUMA_RESOURCELOADER_H

#include <string>
#include <vector>
#include "SpriteShader.h"
#include "ParticlesShader.h"

class ResourceManager
{
public:

    ResourceManager();
    std::vector<std::shared_ptr<Shader>> _shaders;
    std::shared_ptr<Shader> GetShader(std::string name) const;

};
#endif //ZUMA_RESOURCELOADER_H
