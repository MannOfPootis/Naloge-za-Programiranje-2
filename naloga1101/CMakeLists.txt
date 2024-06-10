cmake_minimum_required(VERSION 3.28)
project(naloga1101)

set(CMAKE_CXX_STANDARD 17)

add_executable(naloga1101 main.cpp
        Sensor.h
        Sensor.cpp
        SensorHub.cpp
        TemperatureSensor.cpp
        TemperatureSensorGPS.cpp
        InvalidLocationException.cpp
        InvalidLocationException.h)
