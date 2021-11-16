cmake_minimum_required(VERSION 3.20)
project(static_lib)

set(CMAKE_CXX_STANDARD 17)

add_library(static-lib STATIC library.cpp)

set_target_properties(static-lib PROPERTIES PUBLIC_HEADER library.h)

install(TARGETS static-lib
        PUBLIC_HEADER DESTINATION ./library.h
        ARCHIVE DESTINATION ./library.cpp
        )
