cmake_minimum_required(VERSION 3.27)
project(naloga0301)

set(CMAKE_CXX_STANDARD 17)

add_executable(naloga0301 main.cpp
        Date.cpp
        Date.h
        Location.cpp
        Location.h)
