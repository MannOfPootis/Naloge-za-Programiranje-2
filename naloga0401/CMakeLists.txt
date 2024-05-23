cmake_minimum_required(VERSION 3.27)
project(naloga0401)

set(CMAKE_CXX_STANDARD 17)

add_executable(naloga0401 main.cpp
        Event.cpp
        Event.h
        Date.cpp
        Date.h
        Location.cpp
        Location.h
        EventOrganizer.cpp
        EventOrganizer.h)
