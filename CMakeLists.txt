cmake_minimum_required(VERSION 3.1.0)

project(rt LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)  

set(SOURCES
    src/main.cc)

add_executable(rt ${SOURCES})

