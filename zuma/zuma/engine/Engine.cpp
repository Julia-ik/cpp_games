#include "Engine.h"
#include "ResourceLoader.h"
#include "BallRaw.h"
#include <ctime>



Engine::Engine(int w, int h)
{
    width=w;
    heights=h;
    window = SDL_CreateWindow("  ",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              width,
                              heights,
                              SDL_WINDOW_OPENGL);

    r = SDL_CreateRenderer(window, -1, SDL_WINDOW_OPENGL);
}
/*void Engine::drawGLModel(GLuint programID)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(programID);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VAO);
    glVertexAttribPointer(
            0,
            3,
            GL_FLOAT,
            GL_FALSE,
            0,
            (void*)0
    );

    glDrawArrays(GL_TRIANGLES, 0, 6);

    glDisableVertexAttribArray(0);

    SDL_GL_SwapWindow(window);
}*/

void Engine::initGLL() {
    SDL_GL_CreateContext(window);

    glewExperimental = true;
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "cannot identify GLEWn");
    }
    SDL_Init(SDL_INIT_EVERYTHING);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    _renderer = createShared<Renderer>();
    ResourceManager::LoadShader("../shaders/sprite.vs", "../shaders/sprite.frag",
                                nullptr, "sprite");
    scene.setScale(glm::vec2(width, heights));
    scene._zOrder = 1;
    auto background = createShared<Sprite>(ResourceManager::GetShader("sprite"),
                                           glm::vec2(0.0f, 0.0f), glm::vec2(1, 1),
                                           0.0f, glm::vec2(0.0f),
                                           "/home/lilu/lilu/cpp_games/cpp_games/zuma/zuma/engine/images/fon.png",
                                           glm::vec4(1, 1, 1, 1));
    scene.addNode(background, 1);

    _ballRaw = std::make_shared<BallRaw>(this, 4);

    isActive = true;
}

void Engine::update(float delta)
{
    _ballRaw->update();
    scene.update(delta);
    scene.visit();
    _renderer->draw();
}

void Engine::destroyEngine(SDL_Window **window, SDL_Renderer **render)
{
    SDL_Delay(7000);
    SDL_DestroyWindow(*window);
    SDL_Quit();
}
void Engine::setClipboardTxt(std::string_view text) const
{
    SDL_SetClipboardText(text.data());

}

std::string_view Engine::getClipboardTxt() const
{
    _clipboard = SDL_GetClipboardText();
    return _clipboard;
}

std::vector<int> Engine::chooseColor(int size) const
{
    srand( time( 0 ) );
    std::vector<int> color;
    for(int i=0; i<size; i++){
        if(i>1){
            int temp = rand()%4;
            while(temp == color[i-1] && temp == color[i-2])
            {
                temp=rand()%4;
            }
            color.emplace_back(temp);
        }
        else{
            color.emplace_back(rand()%4);
        }
    }
    return  color;
}
