cmake_minimum_required(VERSION 3.20)
project(game)

set(CMAKE_CXX_STANDARD 17)


add_executable(game main.cpp engine/SRC/SDL/Model.cpp engine/SRC/SDL/Model.h
        engine/SRC/SDL/Model_head.cpp engine/SRC/SDL/Model_head.h
        engine/SRC/SDL/f_triangle.cpp engine/SRC/SDL/f_triangle.h engine/SRC/SDL/v_point.cpp
        engine/SRC/SDL/v_point.h engine/SRC/Shader.cpp
        engine/SRC/Shader.h engine/SRC/Bitmap.cpp engine/SRC/Bitmap.h engine/SRC/Texture.cpp
        engine/SRC/Texture.h engine/SRC/ResourceLoader.cpp engine/SRC/ResourceLoader.h
        engine/SRC/Sprite.cpp engine/SRC/Sprite.h engine/SRC/EventManager.cpp engine/SRC/EventManager.h
        engine/SRC/Tank.cpp engine/SRC/Tank.h engine/SRC/Renderer.cpp engine/SRC/Renderer.h
        engine/SRC/VertexBuffer.cpp engine/SRC/VertexBuffer.h engine/SRC/ImguiManager.cpp engine/SRC/ImguiManager.h)
add_subdirectory(engine)

target_link_libraries(game engine)

