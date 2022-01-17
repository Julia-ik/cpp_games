cmake_minimum_required(VERSION 3.20)
project(zuma)

set(CMAKE_CXX_STANDARD 17)

add_executable(zuma main.cpp engine/Node.cpp engine/Node.h engine/Sprite.cpp engine/Sprite.h
        engine/Shader.cpp engine/Shader.h engine/MeshData.h
        engine/Texture.cpp engine/Texture.h engine/Renderer.cpp engine/Renderer.h
        engine/VertexBuffer.cpp engine/VertexBuffer.h engine/ResourceLoader.cpp
        engine/ResourceLoader.h engine/Frog.cpp engine/Frog.h engine/EventManager.cpp engine/EventManager.h)

add_subdirectory(engine)

target_link_libraries(zuma engine)

