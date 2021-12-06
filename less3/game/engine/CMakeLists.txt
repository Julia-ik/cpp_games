cmake_minimum_required(VERSION 3.20)
project(engine)

set(CMAKE_CXX_STANDARD 17)
if(COMPILER_SUPPORTS_CXX17)

    set(CMAKE_REQUIRED_FLAGS "-std=c++17")
endif()

add_library(engine STATIC SRC/library.cpp Node.cpp Node.h)
#SDL

if(NOT IOS)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/libs/SDL2)
    set(SDL2MAIN_LIBRARY SDL2main)
    set(SDL2_LIBRARY SDL2-static)
    endif()


if(NOT APPLE AND NOT ANDROID AND (UNIX OR MINGW))
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/libs/glew)
    set(GLEW_LIBRARY libglew_static)

endif()



target_link_libraries(engine PRIVATE
        ${SDL2MAIN_LIBRARY} ${SDL2_LIBRARY}
        ${GLEW_LIBRARY} ${OPENGL_LIBRARY} ${STBI_LIBRARY})

target_include_directories(engine PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/SRC
        ${CMAKE_CURRENT_SOURCE_DIR}/libs
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/SDL2/include
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/glew/include
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/stbi)
