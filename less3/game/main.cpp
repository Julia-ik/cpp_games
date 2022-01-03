#include "library.hpp"
#include "SDL/Model_head.h"
//#include "SDL/Model.h"
#include <chrono>
#include <ResourceLoader.h>
#include "Sound.h"
#include "Tank.h"
#include "Button.h"
#include "EventManager.h"

int main()
{
    Engine engine(700, 700);


    engine.initGLL();


    Tank tank(&engine, ResourceManager::GetShader("sprite"),
              glm::vec2(300.0f, 300.0f), glm::vec2(0.65f, 0.4f),
              0.0f, glm::vec2(60.0f, 45.0f));


    Button button(&engine,ResourceManager::GetShader("sprite"),
                  glm::vec2(10.0f, 10.0f), glm::vec2(0.08f, 0.06f),
                  0.0f, glm::vec2(65.0f, 50.0f));


    engine.scene.addNode(std::make_shared<Tank>(tank), 2);

    engine.scene.addNode(std::make_shared<Button>(button), 3);




    auto oldTime = std::chrono::high_resolution_clock::now();
    float val = 0.0f;

    while (engine.isActive){

        engine._eventManager.eventHandler();

        auto curTime = std::chrono::high_resolution_clock::now();
        auto delta = std::chrono::duration_cast<std::chrono::duration<float>>(curTime - oldTime);
        oldTime = curTime;
        val = delta.count();

        engine.update(val);

        SDL_GL_SwapWindow(engine.window);

        glClear(GL_COLOR_BUFFER_BIT);
    }

    return 0;
}
