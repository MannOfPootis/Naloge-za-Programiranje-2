cmake_minimum_required(VERSION 3.28)
project(naloga0802)

set(CMAKE_CXX_STANDARD 17)

add_executable(naloga0802 main.cpp
        CircularLinkedList.cpp
        CircularLinkedList.h
        Node.cpp
        Node.h)
