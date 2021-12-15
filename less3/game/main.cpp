#include "library.hpp"
#include "SDL/Model_head.h"
#include "SDL/Model.h"
#include <chrono>
#include <ResourceLoader.h>
#include "Sound.h"
#include "Tank.h"

int main()
{
    Engine engine(700, 700);
    engine.initGLL();


    /*
    Sprite fireSprite(ResourceManager::GetShader("sprite"),
                      glm::vec2(500.0f, 500.0f), glm::vec2(10.0f, 10.0f),
                      0.0f, glm::vec2(0.5f), "fire");
    engine._spriteRenderers["fire"] = &fireSprite;*/
    Tank tank(&engine, ResourceManager::GetShader("sprite"),
              glm::vec2(300.0f, 300.0f), glm::vec2(85.0f, 40.0f),
              0.0f, glm::vec2(0.5f, 0.5f));

    engine.scene.addNode(std::make_shared<Tank>(tank));



    auto oldTime = std::chrono::high_resolution_clock::now();
    auto val = 0.0;

    while (engine.isActive){

        tank.RegisterEvents();

        auto curTime = std::chrono::high_resolution_clock::now();
        auto delta = std::chrono::duration_cast<std::chrono::duration<float>>(curTime - oldTime);
        oldTime = curTime;
        val = delta.count();

        engine.scene.update(val);
        engine.scene.visit();



        SDL_GL_SwapWindow(engine.window);

        glClear(GL_COLOR_BUFFER_BIT);
    }

    return 0;
}
