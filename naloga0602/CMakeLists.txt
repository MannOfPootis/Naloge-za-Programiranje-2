cmake_minimum_required(VERSION 3.28)
project(naloga0602)

set(CMAKE_CXX_STANDARD 17)

add_executable(naloga0602 main.cpp
        PrintUtility.cpp
        PrintUtility.h
        ColorCode.h
        Graph.cpp
        Graph.h
        Histogram.cpp
        Histogram.h)
