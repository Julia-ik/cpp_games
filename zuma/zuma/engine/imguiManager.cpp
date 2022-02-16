//
// Created by lilu on 14/02/2022.
//

#include "imguiManager.h"
#include "MeshData.h"
#include "Texture.h"
#include "Engine.h"
#include "Shader.h"
#include "Uniforms.h"
#include "glm/gtx/matrix_transform_2d.hpp"

#include <imgui.h>


ImguiManager::ImguiManager(const Engine& engine)
        : _engine(engine)
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    StyleColorsCustom(&ImGui::GetStyle());

    ImGuiIO &io = ImGui::GetIO();
    io.BackendPlatformName = "custom_micro_engine";

    io.KeyMap[ImGuiKey_Tab] = static_cast<size_t>(SDL_SCANCODE_TAB);
    io.KeyMap[ImGuiKey_LeftArrow] = static_cast<size_t>(SDL_SCANCODE_LEFT);
    io.KeyMap[ImGuiKey_RightArrow] = static_cast<size_t>(SDL_SCANCODE_RIGHT);
    io.KeyMap[ImGuiKey_UpArrow] = static_cast<size_t>(SDL_SCANCODE_UP);
    io.KeyMap[ImGuiKey_DownArrow] = static_cast<size_t>(SDL_SCANCODE_DOWN);
    io.KeyMap[ImGuiKey_PageUp] = static_cast<size_t>(SDL_SCANCODE_PAGEUP);
    io.KeyMap[ImGuiKey_PageDown] = static_cast<size_t>(SDL_SCANCODE_PAGEDOWN);
    io.KeyMap[ImGuiKey_Home] = static_cast<size_t>(SDL_SCANCODE_HOME);
    io.KeyMap[ImGuiKey_End] = static_cast<size_t>(SDL_SCANCODE_END);
    io.KeyMap[ImGuiKey_Insert] = static_cast<size_t>(SDL_SCANCODE_INSERT);
    io.KeyMap[ImGuiKey_Delete] = static_cast<size_t>(SDL_SCANCODE_DELETE);
    io.KeyMap[ImGuiKey_Backspace] = static_cast<size_t>(SDL_SCANCODE_BACKSPACE);
    io.KeyMap[ImGuiKey_Space] = static_cast<size_t>(SDL_SCANCODE_SPACE);
    io.KeyMap[ImGuiKey_Enter] = static_cast<size_t>(SDL_SCANCODE_RETURN);
    io.KeyMap[ImGuiKey_Escape] = static_cast<size_t>(SDL_SCANCODE_ESCAPE);
    io.KeyMap[ImGuiKey_A] = static_cast<size_t>(SDL_SCANCODE_A);
    io.KeyMap[ImGuiKey_C] = static_cast<size_t>(SDL_SCANCODE_C);
    io.KeyMap[ImGuiKey_V] = static_cast<size_t>(SDL_SCANCODE_V);
    io.KeyMap[ImGuiKey_X] = static_cast<size_t>(SDL_SCANCODE_X);
    io.KeyMap[ImGuiKey_Y] = static_cast<size_t>(SDL_SCANCODE_Y);
    io.KeyMap[ImGuiKey_Z] = static_cast<size_t>(SDL_SCANCODE_Z);

    io.RenderDrawListsFn = nullptr;

    int width = 0;
    int height = 0;
    unsigned char *dataPtr;
    io.Fonts->GetTexDataAsRGBA32(&dataPtr, &width, &height);
    std::vector<unsigned char> image;
    image = {dataPtr, dataPtr+(width*height*4)};

    Bitmap bitmap(Bitmap::Format::Rgba, std::move(image), glm::vec2{width, height});

    io.SetClipboardTextFn = [](void *userData, const char *text)
    {
        auto self = static_cast<ImguiManager*>(userData);
        self->_engine.setClipboardTxt(text);
    };

    io.GetClipboardTextFn = [](void *userData) -> const char *
    {
        auto self = static_cast<ImguiManager*>(userData);
        return self->_engine.getClipboardTxt().data();
    };

    io.ClipboardUserData = this;

    _command.program = _engine._resManager->GetShader("imgui");

    _textureUniform = _command.program->createTextureUniform("uTexture", _command.program);
    _textureUniform->texture = engine._renderer->createTexture(std::move(bitmap));

    _colorUniform = _command.program->createVec4Uniform("uColor", _command.program);
    _colorUniform->value = glm::vec4(0,1,1,0);

    _screenSizeUniform = _command.program->createVec2Uniform("uScreenSize", _command.program);

    _transformUniform = _command.program->createMat3Uniform("uTransform", _command.program);

    _command._transformUniform = _transformUniform;
    _command._textureUniform = _textureUniform;
    _command._screenSizeUniform = _screenSizeUniform;
    _command._colorUniform = _colorUniform;


    _engine._eventManager.addHandler([this](const SDL_Event &e)
                                     {
                                         if(e.type == SDL_TEXTINPUT)
                                         {
                                             ImGuiIO &io = ImGui::GetIO();
                                             io.AddInputCharactersUTF8(e.text.text);
                                         }
                                     });

    _engine._eventManager.addHandler( [this](const SDL_Event &e)
                                      {
                                          if(e.type == SDL_KEYDOWN) {
                                              ImGuiIO &io = ImGui::GetIO();
                                              size_t key = static_cast<size_t>(e.key.type);

                                              io.KeysDown[key] = e.type == SDL_KEYDOWN;
                                          }

                                      });

    _engine._eventManager.addHandler ([this](const SDL_Event &e)
                                      {
                                          if (e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_LEFT)
                                          {
                                              _lMousePressed = false;
                                          }
                                          else if (e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_RIGHT)
                                          {
                                              _rMousePressed = false;
                                          }
                                          else if (e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_MIDDLE)
                                          {
                                              _mMousePressed = false;
                                          }
                                          else if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
                                          {
                                              _lMousePressed = true;
                                          }
                                          else if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_RIGHT)
                                          {
                                              _rMousePressed = true;
                                          }
                                          else if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_MIDDLE)
                                          {
                                              _mMousePressed = true;
                                          }
                                          else if (e.type == SDL_MOUSEMOTION)
                                          {
                                              _mousePos = glm::vec2{e.motion.x, e.motion.y};
                                          }
                                      });

    _engine._eventManager.addHandler([this](const SDL_Event &e)
                                     {
                                         if(e.type == SDL_MOUSEWHEEL)
                                         {
                                             if (e.wheel.y > 0) {
                                                 _mouseWheel = 1;
                                             }
                                             if (e.wheel.y < 0) {
                                                 _mouseWheel = -1;
                                             }
                                         }
                                     });
}

void ImguiManager::visit()
{
    ImGuiIO &io = ImGui::GetIO();
    io.DisplaySize = ImVec2(float(_engine.width), float(_engine.heights));

    io.MousePos = {_mousePos.x, _mousePos.y};

    io.MouseDown[0] = _lMousePressed;
    io.MouseDown[1] = _rMousePressed;
    io.MouseDown[2] = _mMousePressed;

    io.MouseWheel = _mouseWheel;
    _mouseWheel = 0.0f;

    io.DeltaTime = 0.1f;

    ImGui::NewFrame();

    ImGui::Begin("Menu");

    if (ImGui::Button("Pause"))
    {
        if(_engine.isPaused)
        {
            _engine.isPaused = false;
        }
        else
        {
            _engine.isPaused = true;
        }

    }
    if (ImGui::Button("Mute"))
    {
        _engine._soundManager.volume=0.0f;
    }
    if(ImGui::SliderFloat("volume", &_engine._sounds[0]->_soundManager->volume, 0, 1))
    {
        _engine._soundManager.volume;
    };
    if (ImGui::Button("Exit"))
    {
        _engine.isActive = false;
    }
    ImGui::End();
    ImGui::Render();

    auto drawData = ImGui::GetDrawData();

    for (int n = 0; n < drawData->CmdListsCount; ++n)
    {
        const ImDrawList *cmd_list = drawData->CmdLists[n];

        auto vertex_data = reinterpret_cast<MeshData::Vertex *>(cmd_list->VtxBuffer.Data);
        size_t vert_count = static_cast<size_t>(cmd_list->VtxBuffer.size());

        const uint32_t *indexes = cmd_list->IdxBuffer.Data;
        size_t index_count = static_cast<size_t>(cmd_list->IdxBuffer.size());

        MeshData meshData;

        meshData.vertices = {vertex_data, vertex_data + vert_count};


        meshData.indexes={indexes, indexes+index_count};

        auto vertexBuffer = _engine._renderer->createVertexBuffer(std::move(meshData));

        _command.vertexBuffer = std::move(vertexBuffer);
        _transformUniform->value = glm::mat3(1.0f);
        _screenSizeUniform->value.x = _engine.width;
        _screenSizeUniform->value.y = _engine.heights;

        size_t offset = 0;
        for (int cmd_i = 0; cmd_i < cmd_list->CmdBuffer.Size; cmd_i++)
        {
            const ImDrawCmd *pcmd = &cmd_list->CmdBuffer[cmd_i];


            _command.sub.emplace();
            _command.sub->num = pcmd->ElemCount;
            _command.sub->offset = offset * sizeof(std::uint32_t);

            _command.scissor = glm::vec4(pcmd->ClipRect.x, pcmd->ClipRect.y, pcmd->ClipRect.z, pcmd->ClipRect.w);

            _engine._renderer->addCommand(_command);

            offset += pcmd->ElemCount;
        }
    }
}

void ImguiManager::StyleColorsCustom(ImGuiStyle* dst)
{
    ImGuiStyle *style = dst ? dst : &ImGui::GetStyle();
    ImVec4 *colors = style->Colors;


    colors[ImGuiCol_FrameBg]                = ImVec4(0.42, 0.48, 0.16, 0.54);
    colors[ImGuiCol_FrameBgHovered]         = ImVec4(0.85, 0.98, 0.26, 0.40);
    colors[ImGuiCol_FrameBgActive]          = ImVec4(0.85, 0.98, 0.26, 0.67);
    colors[ImGuiCol_TitleBg]                = ImVec4(0.04, 0.04, 0.04, 1.00);
    colors[ImGuiCol_TitleBgActive]          = ImVec4(0.42, 0.48, 0.16, 1.00);
    colors[ImGuiCol_TitleBgCollapsed]       = ImVec4(0.00, 0.00, 0.00, 0.51);
    colors[ImGuiCol_CheckMark]              = ImVec4(0.85, 0.98, 0.26, 1.00);
    colors[ImGuiCol_SliderGrab]             = ImVec4(0.77, 0.88, 0.24, 1.00);
    colors[ImGuiCol_SliderGrabActive]       = ImVec4(0.85, 0.98, 0.26, 1.00);
    colors[ImGuiCol_Button]                 = ImVec4(0.85, 0.98, 0.26, 0.40);
    colors[ImGuiCol_ButtonHovered]          = ImVec4(0.85, 0.98, 0.26, 1.00);
    colors[ImGuiCol_ButtonActive]           = ImVec4(0.82, 0.98, 0.06, 1.00);
    colors[ImGuiCol_Header]                 = ImVec4(0.85, 0.98, 0.26, 0.31);
    colors[ImGuiCol_HeaderHovered]          = ImVec4(0.85, 0.98, 0.26, 0.80);
    colors[ImGuiCol_HeaderActive]           = ImVec4(0.85, 0.98, 0.26, 1.00);
    colors[ImGuiCol_Separator]              = colors[ImGuiCol_Border];
    colors[ImGuiCol_SeparatorHovered]       = ImVec4(0.63, 0.75, 0.10, 0.78);
    colors[ImGuiCol_SeparatorActive]        = ImVec4(0.63, 0.75, 0.10, 1.00);
    colors[ImGuiCol_ResizeGrip]             = ImVec4(0.85, 0.98, 0.26, 0.25);
    colors[ImGuiCol_ResizeGripHovered]      = ImVec4(0.85, 0.98, 0.26, 0.67);
    colors[ImGuiCol_ResizeGripActive]       = ImVec4(0.85, 0.98, 0.26, 0.95);
    colors[ImGuiCol_PlotLines]              = ImVec4(0.61, 0.61, 0.61, 1.00);
    colors[ImGuiCol_PlotLinesHovered]       = ImVec4(1.00, 0.81, 0.35, 1.00);
    colors[ImGuiCol_TextSelectedBg]         = ImVec4(0.85, 0.98, 0.26, 0.35);
    colors[ImGuiCol_Text]                   = ImVec4(1.00, 1.00, 1.00, 1.00);
    colors[ImGuiCol_TextDisabled]           = ImVec4(0.50, 0.50, 0.50, 1.00);
    colors[ImGuiCol_WindowBg]               = ImVec4(0.06, 0.06, 0.06, 0.94);
    colors[ImGuiCol_ChildWindowBg]          = ImVec4(1.00, 1.00, 1.00, 0.00);
    colors[ImGuiCol_PopupBg]                = ImVec4(0.08, 0.08, 0.08, 0.94);
    colors[ImGuiCol_Border]                 = ImVec4(0.43, 0.43, 0.50, 0.50);
    colors[ImGuiCol_BorderShadow]           = ImVec4(0.00, 0.00, 0.00, 0.00);
    colors[ImGuiCol_MenuBarBg]              = ImVec4(0.14, 0.14, 0.14, 1.00);
    colors[ImGuiCol_ScrollbarBg]            = ImVec4(0.02, 0.02, 0.02, 0.53);
    colors[ImGuiCol_ScrollbarGrab]          = ImVec4(0.31, 0.31, 0.31, 1.00);
    colors[ImGuiCol_ScrollbarGrabHovered]   = ImVec4(0.41, 0.41, 0.41, 1.00);
    colors[ImGuiCol_ScrollbarGrabActive]    = ImVec4(0.51, 0.51, 0.51, 1.00);
    colors[ImGuiCol_PlotHistogram]          = ImVec4(0.90, 0.70, 0.00, 1.00);
    colors[ImGuiCol_PlotHistogramHovered]   = ImVec4(1.00, 0.60, 0.00, 1.00);
    colors[ImGuiCol_ModalWindowDarkening]   = ImVec4(0.80, 0.80, 0.80, 0.35);
}