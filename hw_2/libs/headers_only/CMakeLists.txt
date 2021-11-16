cmake_minimum_required(VERSION 3.20)
project(headers_only)

set(CMAKE_CXX_STANDARD 17)

add_library(header-lib INTERFACE ./headers_lib.ipp)
set_target_properties(header-lib PROPERTIES PUBLIC_HEADER ./headers_lib.ipp)

install(TARGETS header-lib
        PUBLIC_HEADER
        DESTINATION ./headers_lib.ipp
        )

set(CMAKE_CXX_STANDARD 17)

