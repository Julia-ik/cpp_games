cmake_minimum_required(VERSION 3.20)
project(dynamic_lib)

set(CMAKE_CXX_STANDARD 17)

add_library(dynamic-lib SHARED library-dynamic.cpp)

set_target_properties(dynamic-lib PROPERTIES PUBLIC_HEADER library-dynamic.h)


install(TARGETS dynamic-lib
        PUBLIC_HEADER DESTINATION ./library-dynamic.h
        ARCHIVE DESTINATION ./library-dynamic.cpp
        )
