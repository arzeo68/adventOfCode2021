cmake_minimum_required(VERSION 3.5)
project(adventOfCode)

set(CMAKE_CXX_STANDARD 20)

add_executable(adventOfCode
        main.cpp
        header.hpp
        lib.cpp
        dayO2.cpp
        day03.cpp
        day04.cpp
        day05.cpp
        day06.cpp day07.cpp)