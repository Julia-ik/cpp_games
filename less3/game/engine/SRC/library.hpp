#ifndef ENGINE_LIBRARY_H
#define ENGINE_LIBRARY_H
#define GLEW_NO_GLU
#include <string_view>
#include <SDL.h>
#include "vector"
#include "SDL/Model.h"
#include "Sprite.h"
#include <GL/glew.h>
#include <map>
#include "EventManager.h"

class Renderer;
class ImguiManager;

class Engine
{

public:
    std::shared_ptr<Renderer> _renderer;
    std::shared_ptr<ImguiManager> _imguiManager;
    SDL_Window *window;
    SDL_Renderer *r;
    AudioManager audioManager;
    EventManager _eventManager;
    int width;
    int heights;
    mutable std::string_view _clipboard;
    SDL_bool done = SDL_FALSE;

    uint32_t VAO;
    uint32_t VBO;
    uint32_t IBO;
    Node scene;
    GLuint programID = 0;
    std::vector<std::shared_ptr<Sound>> _sounds;

    bool isActive;


    void update(float delta);

    GLuint LoadShaders(const char * vertex_file_path, const char* fragment_file_path);
    Engine(int w, int h);
    void setClipboardTxt(std::string_view text) const;
    std::string_view getClipboardTxt() const;
    void drawWindow(Model * model, bool isItGL);
    void flip(SDL_Renderer **r);
    GLuint initGL();
    void initSDL();
    void printVersionInfo ();
    void drawGLModel(GLuint programID);
    void drawSDLModel(Model * model);
    void drawTriangle(SDL_Renderer **r, float x1, float y1, float x2, float y2, float x3, float y3);
    void destroyEngine(SDL_Window **window, SDL_Renderer **render);

    void checkForErrors();

    void initGLL();

    void Render();

    void RegisterEvents();

    void move(Sprite *sprite);

    void moveLeft(Sprite *sprite);

    void moveRight(Sprite *sprite);

    void moveBack(Sprite *sprite);

    template<typename T, typename... Args>
    std::shared_ptr<T> createShared(Args&&... args) const
    {
        if constexpr(std::is_constructible_v<T, const Engine&, Args&&...>)
        {
            return std::make_shared<T>(*this, std::forward<Args>(args)...);
        }
        else
        {
            return std::make_shared<T>(std::forward<Args>(args)...);
        }
    }
};
#endif //ENGINE_LIBRARY_H
