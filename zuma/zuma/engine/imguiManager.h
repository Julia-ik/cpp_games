//
// Created by lilu on 14/02/2022.
//

#ifndef ZUMA_IMGUIMANAGER_H
#define ZUMA_IMGUIMANAGER_H

#include <memory>
#include "Renderer.h"
#include "glm/glm.hpp"
#include "EventManager.h"
#include "imgui.h"

class Texture;
class Engine;
class GlTextureUniform;
class GlMat3Uniform;
class GlVec2Uniform;
class GlVec4Uniform;

class ImguiManager final
{
public:
    Renderer::Command _command;
    std::shared_ptr<GlVec2Uniform> _screenSizeUniform;
    std::shared_ptr<GlMat3Uniform>  _transformUniform;
    std::shared_ptr<GlTextureUniform>  _textureUniform;
    std::shared_ptr<GlVec4Uniform>  _colorUniform;
    explicit ImguiManager(const Engine& engine);
    void visit();

private:
    const Engine& _engine;

    bool show_demo_window = true;

    bool _rMousePressed {false};
    bool _lMousePressed {false};
    bool _mMousePressed {false};

    glm::vec2 _mousePos;

    float _mouseWheel = 0.0f;

    void StyleColorsCustom(ImGuiStyle *dst);
};

#endif //ZUMA_IMGUIMANAGER_H
