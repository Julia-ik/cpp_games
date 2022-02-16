
//
// Created by lilu on 16/01/2022.
//

#include "ResourceLoader.h"
#include "ImguiShader.h"

ResourceManager::ResourceManager()
{
}

std::shared_ptr<Shader> ResourceManager::GetShader(std::string name)
{
    if(name == "particles")
    {
        return std::make_shared<ParticlesShader>();
    }
    else if(name == "imgui")
    {
        return std::make_shared<ImguiShader>();
    }
    else
    {
        return std::make_shared<SpriteShader>();
    }
}
