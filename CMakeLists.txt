cmake_minimum_required(VERSION 3.1.0)

project(rt LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)  

set(SOURCES
    src/main.cpp)

include_directories(lib)

add_executable(rt ${SOURCES})

