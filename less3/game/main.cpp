#include "library.hpp"
#include "Model_head.h"
#include "Model.h"
#include <chrono>
#include <ResourceLoader.h>

int main()
{
    bool isItGL = true;
    Engine engine(700, 700);

    Model_head source;
    Model model(source.v_source, source.f_source, engine.width, engine.heights);

    //engine.drawWindow(&model, isItGL);
    engine.initGLL();

    SpriteRenderer bodySprite(ResourceManager::GetShader("sprite"),
                              glm::vec2(300.0f, 300.0f), glm::vec2(85.0f, 40.0f),
                              0.0f, 0.5f);
    engine._spriteRenderers["body"] = &bodySprite;
    SpriteRenderer gunSprite(ResourceManager::GetShader("sprite"),
                             glm::vec2(engine._spriteRenderers["body"]->_position.x+21.5,
                                       engine._spriteRenderers["body"]->_position.y+8.0f), glm::vec2(70.0f, 30.0f),
                             45.0f, 0.3f);
    engine._spriteRenderers["gun"] = &gunSprite;
    SpriteRenderer fireSprite(ResourceManager::GetShader("sprite"),
                              glm::vec2(500.0f, 500.0f), glm::vec2(10.0f, 10.0f),
                              0.0f, 0.5f);
    engine._spriteRenderers["fire"] = &fireSprite;


    auto oldTime = std::chrono::high_resolution_clock::now();
    auto val = 0.0;

    while (engine.isActive){

        engine.RegisterEvents();

        auto curTime = std::chrono::high_resolution_clock::now();
        auto delta = std::chrono::duration_cast<std::chrono::duration<double>>(curTime - oldTime);
        oldTime = curTime;
        val += delta.count();

        engine.Render();

        SDL_GL_SwapWindow(engine.window);

        glClear(GL_COLOR_BUFFER_BIT);
    }

    return 0;
}

// gonna leave it here just for future...

//    FILE * f = fopen("/home/lilu/lilu/cpp_games/cpp_games/less3/game/koko.txt", "r");
//    int val;
//    fscanf(f, "%d", &val);
//    bool succes = f !=nullptr;
//std::ifstream f("/home/lilu/lilu/cpp_games/cpp_games/less3/game/koko.txt");
//int v;
//f >> v;