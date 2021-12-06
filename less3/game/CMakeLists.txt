cmake_minimum_required(VERSION 3.20)
project(game)

set(CMAKE_CXX_STANDARD 17)


add_executable(game main.cpp Model.cpp Model.h Model_head.cpp Model_head.h f_triangle.cpp f_triangle.h v_point.cpp v_point.h engine/SRC/Sprite.cpp engine/SRC/Sprite.h engine/Mesh.cpp engine/Mesh.h engine/SRC/Shader.cpp engine/SRC/Shader.h engine/Bitmap.cpp engine/Bitmap.h engine/SRC/Texture.cpp engine/SRC/Texture.h engine/SRC/ResourceLoader.cpp engine/SRC/ResourceLoader.h engine/SRC/SpriteRenderer.cpp engine/SRC/SpriteRenderer.h engine/SRC/EventManager.cpp engine/SRC/EventManager.h)
add_subdirectory(engine)

target_link_libraries(game engine)

