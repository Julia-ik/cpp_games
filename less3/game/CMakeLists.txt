cmake_minimum_required(VERSION 3.20)
project(game)

set(CMAKE_CXX_STANDARD 17)


add_executable(game main.cpp Model.cpp Model.h Model_head.cpp Model_head.h f_triangle.cpp f_triangle.h v_point.cpp v_point.h)
add_subdirectory(engine)

target_link_libraries(game engine)

