cmake_minimum_required(VERSION 3.20)
project(zuma)

set(CMAKE_CXX_STANDARD 17)

set(GAME_SRC main.cpp engine/Node.cpp engine/Node.h engine/Sprite.cpp engine/Sprite.h
        engine/Shader.cpp engine/Shader.h engine/MeshData.h
        engine/Texture.cpp engine/Texture.h engine/Renderer.cpp engine/Renderer.h
        engine/VertexBuffer.cpp engine/VertexBuffer.h engine/ResourceLoader.cpp
        engine/ResourceLoader.h engine/Frog.cpp engine/Frog.h engine/EventManager.cpp engine/EventManager.h
        engine/ResourceManager.h GameScene.cpp GameScene.h LoadingScreen.cpp LoadingScreen.h engine/BallRaw.cpp
        engine/BallRaw.h engine/LevelBall.cpp engine/LevelBall.h engine/Color.h)

if (ANDROID)

add_library(zuma SHARED ${GAME_SRC} engine/TaskManager.cpp engine/TaskManager.h)

else()

add_executable(zuma ${GAME_SRC})

endif()

add_subdirectory(engine)

target_link_libraries(zuma engine)

