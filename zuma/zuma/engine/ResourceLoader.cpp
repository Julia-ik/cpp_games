
//
// Created by lilu on 16/01/2022.
//

#include "ResourceLoader.h"


ResourceManager::ResourceManager()
{
    auto spriteShader = std::make_shared<SpriteShader>();
    auto partShader = std::make_shared<ParticlesShader>();
    _shaders.emplace_back(spriteShader);
    _shaders.emplace_back(partShader);
}
std::shared_ptr<Shader> ResourceManager::GetShader(std::string name) const {
    if(name == "particles")
    {
        return _shaders[1];
    }
    else
    {
        return _shaders[0];
    }
}
