#include "library.hpp"
#include "SDL/Model.h"
#include "ResourceLoader.h"
#include <GL/glew.h>
#include "Sound.h"
#include <SDL.h>
#include <stdio.h>
#include <glm/glm.hpp>
#include <imgui.h>
#include <glm/gtc/matrix_transform.hpp>


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

void Engine::drawWindow(Model *model, bool isItGL)
{
    if(isItGL)
    {

    }
    else{
        initSDL();
    }

    do
    {
        isItGL ? drawGLModel(programID) : drawSDLModel(model);
    }
    while( true) ;

}

void Engine::drawGLModel(GLuint programID)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(programID);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VAO);
    glVertexAttribPointer(
            0,
            3,                  // Размер
            GL_FLOAT,           // Тип
            GL_FALSE,           // Указывает, что значения не нормализованы
            0,                  // Шаг
            (void*)0            // Смещение массива в буфере
    );

    glDrawArrays(GL_TRIANGLES, 0, 6); // Начиная с вершины 0, всего 3 вершины -> один треугольник

    glDisableVertexAttribArray(0);

    SDL_GL_SwapWindow(window);
}
void Engine::initSDL()
{
    printVersionInfo();

    SDL_Init(SDL_INIT_VIDEO);
}

void Engine::printVersionInfo()
{
    SDL_version version = {0, 0, 0};
    SDL_GetVersion(&version);
    printf("SDL Version: %d.%d.%d, version.major, version.patch, version minor");
}

void Engine::initGLL()
{
    SDL_GL_CreateContext(window);
    SDL_Init(SDL_INIT_EVERYTHING);

    glewExperimental=true;
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "cannot identify GLEWn");
    }

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    ResourceManager::LoadShader("../shaders/sprite.vs", "../shaders/sprite.frag",
                                nullptr, "sprite");

    ResourceManager::LoadShader("../shaders/sprite.vs", "../shaders/sprite.frag",
                                nullptr, "sprite");

    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->width),
                                      static_cast<float>(this->heights), 0.0f, -1.0f, 1.0f);
    ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);

    ResourceManager::LoadTexture("/home/lilu/lilu/cpp_games/cpp_games/less3/game/images/gun.png",
                                 true, "gun");
    ResourceManager::LoadTexture("/home/lilu/lilu/cpp_games/cpp_games/less3/game/images/body.png",
                                 true, "body");
    ResourceManager::LoadTexture("/home/lilu/lilu/cpp_games/cpp_games/less3/game/images/fire2.png",
                                 true, "fire");
    ResourceManager::LoadTexture("/home/lilu/lilu/cpp_games/cpp_games/less3/game/images/grass.png",
                                 true, "grass");


    audioManager.init();
    _sounds.push_back(std::make_shared<Sound>("/home/lilu/lilu/cpp_games/cpp_games/less3/game/sound/dramatic.wav",
                                              &audioManager, "theme"));
    scene.setScale(glm::vec2(width, heights));
    scene.addNode(std::make_shared<Sprite>(ResourceManager::GetShader("sprite"),
                                         glm::vec2(0.0f, 0.0f), glm::vec2(width, heights),
                                          0.0f, glm::vec2(0.5f),glm::vec4(0.0f,1.0f,0.0f,1.0f), "grass"));

    _sounds[0]->play();
    isActive = true;
}



void Engine::drawTriangle(SDL_Renderer **r, float x1, float y1, float x2, float y2, float x3, float y3)
{
  SDL_SetRenderDrawColor(*r, 255, 0, 0, SDL_ALPHA_OPAQUE);

  SDL_RenderDrawLine(*r,x1, y1, x2, y2);
  SDL_RenderDrawLine(*r,x1,y1,x3,y3);
  SDL_RenderDrawLine(*r, x2,y2,x3,y3);
  SDL_RenderPresent(*r);

}


void Engine::drawSDLModel(Model * model)
{

    for(int i=0; i<model->fvector.size();i++)
    {
        int x01 = model->vvector[model->fvector[i]->first]-> x;
        int y01 = model->vvector[model->fvector[i]->first]-> y;
        int x02 = model->vvector[model->fvector[i]->second]->x;
        int y02 = model->vvector[model->fvector[i]->second]->y;
        int x03 = model->vvector[model->fvector[i]->third]-> x;
        int y03 = model->vvector[model->fvector[i]->third]-> y;

        drawTriangle(&r,x01,y01,x02,y02,x03,y03);
    }

    destroyEngine(&window,&r);
}

void Engine::destroyEngine(SDL_Window **window, SDL_Renderer **renderer)
{
    SDL_Delay(7000);
    SDL_DestroyWindow(*window);
    SDL_Quit();
}

/*void Engine::checkForErrors()
{
    GLenum err(glGetError());
    while(err!=SDL_GL_CONTEXT_NO_ERROR)
    {
        std::string error;
        switch(err)
        {
            case GL_INVALID_OPERATION:error ="INVALID_FRAMEBUFFER_OPERATION";
            break;
            case GL_INVALID_ENUM:error = "INVALID_ENUM";
            break;
            case GL_INVALID_VALUE:error="OUT_OF_MEMORY";
            break;
            case GL_INVALID_FRAMEBUFFER_OPERATION:error ="INVALID_FRAMEBUFFER_OPERATOR";
            break;
            default:error = "UNKNOWN";
            break;
        }

        std::cerr<<"GL_"<<error<<": 0x"<<std::hex<<err<<std::dec<<"-"<<std::endl;
        err=glGetError();
    }*/
//}

