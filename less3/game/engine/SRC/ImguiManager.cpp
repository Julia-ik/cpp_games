#include "ImguiManager.h"
#include "MeshData.h"

#include <Texture.h>
#include <library.hpp>
#include <Shader.h>
#include "Uniforms.h"

#include <imgui.h>


ImguiManager::ImguiManager(const Engine& engine)
        : _engine(engine)
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();
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

    //TODO: texture map
    //io.Fonts->TexID = (void *) 0x42;

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

    _command.program = std::make_shared<Shader>(ResourceManager::GetShader("sprite"));

    _textureUniform = _command.program->createTextureUniform("uTexture", _command.program);
    _textureUniform->texture = engine._renderer->createTexture(std::move(bitmap));

    _screenSizeUniform = _command.program->createVec2Uniform("uScreenSize", _command.program);
    _transformUniform = _command.program->createMat3Uniform("uTransform", _command.program);

    _command._transformUniform = _transformUniform;
    _command._textureUniform = _textureUniform;
    _command._screenSizeUniform = _screenSizeUniform;


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

    io.DisplaySize = ImVec2(float(_engine.width/8), float(_engine.heights/8));

    io.MousePos = {_mousePos.x, _mousePos.y};

    io.MouseDown[0] = _lMousePressed;
    io.MouseDown[1] = _rMousePressed;
    io.MouseDown[2] = _mMousePressed;

    io.MouseWheel = _mouseWheel;
    _mouseWheel = 0.0f;

    io.DeltaTime = 0.1f;

    ImGui::NewFrame();

    ImGui::ShowDemoWindow(&show_demo_window);
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
        MeshData::Vertex vertex;

        for(int i = 0; i<vertex_data->position.length();i+=2)
        {
            MeshData::Vertex vertex;
            vertex.color = vertex_data->color;
            vertex.position = glm::vec2(vertex_data->position[i], vertex_data->position[i+1]);
            vertex.textureCoords = glm::vec2(vertex_data->textureCoords[i], vertex_data->textureCoords[i+1]);
            meshData.vertices.emplace_back(vertex);

        }
        meshData.indexes={indexes, indexes+index_count};

        auto vertexBuffer = _engine._renderer->createVertexBuffer(std::move(meshData));

        _command.vertexBuffer = std::move(vertexBuffer);
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
