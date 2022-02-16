#include <chrono>
#include "engine/Engine.h"
#include "engine/Frog.h"

int main()
{
    Engine engine(700, 700);
    engine.initGLL();

    Frog frog(&engine,
              glm::vec2(280.0f, 270.0f), glm::vec2(0.5f, 0.5f),
              0.0f, glm::vec2(125.0f, 125.0f));

    engine.scene.addNode(std::make_shared<Frog>(frog), 2);

        auto oldTime = std::chrono::high_resolution_clock::now();
        float val = 0.0f;

        while (engine.isActive)
        {
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