cmake_minimum_required(VERSION 3.20)
project(game)

set(CMAKE_CXX_STANDARD 17)


add_executable(game main.cpp)
add_subdirectory(engine)

target_link_libraries(game engine)

