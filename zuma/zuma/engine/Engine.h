#ifndef ENGINE_LIBRARY_H
#define ENGINE_LIBRARY_H
#define GLEW_NO_GLU
#include <SDL.h>
#include <GL/glew.h>
#include <memory>
#include "Renderer.h"
#include "Sprite.h"
#include "EventManager.h"
#include "BallRaw.h"
#include "SoundManager.h"
#include "Sound.h"


class ImguiManager;
enum ColOfBall
{
    ORANGE = 0,
    PURPLE = 1,
    BLUE = 2,
    YELLOW = 3
};

class Engine
{
public:
    std::shared_ptr<ImguiManager> _imguiManager;
    std::shared_ptr<Renderer> _renderer;
    SDL_Window *window;
    SDL_Renderer *r;
    EventManager _eventManager;
    SoundManager _soundManager;
    std::shared_ptr<ResourceManager> _resManager;
    int width;
    int heights;
    mutable std::string_view _clipboard;
    SDL_bool done = SDL_FALSE;
    mutable std::vector<int> dataToClear;
    void clearData();

    uint32_t VAO;
    uint32_t VBO;
    uint32_t IBO;
    mutable Node scene;
    std::shared_ptr<BallRaw> _ballRaw;
    GLuint programID = 0;
    std::vector<std::shared_ptr<Sound>> _sounds;
    mutable bool isActive;
    mutable bool isPaused= false;
    Engine(int w, int h);

    void update(float delta);
    void initGLL();
    std::vector<int> chooseColor(int size) const;
   // void drawGLModel(GLuint programID);

    void destroyEngine(SDL_Window **window, SDL_Renderer **render);

    void setClipboardTxt(std::string_view text) const;

    std::string_view getClipboardTxt() const;

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
