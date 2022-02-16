cmake_minimum_required(VERSION 3.20)
project(Engine)

set(CMAKE_CXX_STANDARD 17)
if(COMPILER_SUPPORTS_CXX17)

    set(CMAKE_REQUIRED_FLAGS "-std=c++17")
endif()

add_library(engine STATIC Engine.cpp Node.cpp Node.h Sprite.cpp Sprite.h
        Shader.cpp Shader.h Bitmap.cpp Bitmap.h MeshData.h Uniforms.h
        Texture.cpp Texture.h Renderer.cpp Renderer.h VertexBuffer.cpp
        VertexBuffer.h ResourceLoader.cpp ResourceLoader.h
        Frog.cpp Frog.h EventManager.cpp EventManager.h Ball.cpp Ball.h
        ResourceManager.h TaskManager.cpp TaskManager.h BallRaw.cpp BallRaw.h LevelBall.cpp
        LevelBall.h Color.h Particles.cpp Particles.h ParticleBuffer.cpp ParticleBuffer.h
        ParticlesShader.cpp ParticlesShader.h SpriteShader.cpp SpriteShader.h FileManager.cpp
        FileManager.h BaseVertexBuffer.h SoundManager.cpp SoundManager.h Sound.cpp Sound.h
        imguiManager.cpp imguiManager.h ImguiShader.cpp ImguiShader.h)
#SDL

if(NOT IOS)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/libs/SDL2)
    set(SDL2MAIN_LIBRARY SDL2main)
    set(SDL2_LIBRARY SDL2-static)
endif()

if(ANDROID)
    set(OPENGL_LIBRARY OpenGL)
else()
    find_library(OPENGL_LIBRARY OpenGL)
endif()

if(NOT APPLE AND NOT ANDROID AND (UNIX OR MINGW))
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/libs/glew)
    set(GLEW_LIBRARY libglew_static)

endif()


add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/libs/imgui)

target_link_libraries(engine PRIVATE
        ${SDL2MAIN_LIBRARY} ${SDL2_LIBRARY}
        ${GLEW_LIBRARY} ${OPENGL_LIBRARY} ${STBI_LIBRARY} imgui)

target_include_directories(engine PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/SRC
        ${CMAKE_CURRENT_SOURCE_DIR}/libs
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/SDL2/include
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/glew/include
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/stbi
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/imgui)
