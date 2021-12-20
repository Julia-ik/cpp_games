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
              glm::vec2(300.0f, 300.0f), glm::vec2(85.0f, 40.0f),
              0.0f, glm::vec2(0.5f, 0.5f));


    Button button(ResourceManager::GetShader("sprite"),
                  glm::vec2(10.0f, 10.0f), glm::vec2(60.0f, 60.0f),
                  0.0f, glm::vec2(0.0f, 0.0f));

    engine.scene.addNode(std::make_shared<Tank>(tank), 2);

    engine.scene.addNode(std::make_shared<Button>(button), 3);



    auto oldTime = std::chrono::high_resolution_clock::now();
    auto val = 0.0;

    while (engine.isActive){

        EventManager eventManager(&engine, &tank, &button);
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
