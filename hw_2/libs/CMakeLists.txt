cmake_minimum_required(VERSION 3.20)
project(libs)

set(CMAKE_CXX_STANDARD 17)

add_executable(libs main.cpp)

target_include_directories(libs PRIVATE /usr/local/./headers_lib.ipp)

target_include_directories(libs PRIVATE /usr/local/./library.h )
target_link_directories(libs PRIVATE /usr/local/./library.cpp)
target_link_libraries(libs libstatic-lib.a)

target_include_directories(libs PRIVATE /usr/local/library-dynamic.h/)
target_link_directories(libs PRIVATE /usr/local/lib/)
target_link_libraries(libs libdynamic-lib.so)


