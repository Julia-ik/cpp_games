#ifndef GAME_IMGUIMANAGER_HPP
#define GAME_IMGUIMANAGER_HPP

#include <memory>
#include "Renderer.h"
#include "glm/glm.hpp"
#include "EventManager.h"

class Texture;
class Engine;

class ImguiManager final
{
public:
    Renderer::Command _command;
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
};


#endif //GAME_IMGUIMANAGER_HPP
