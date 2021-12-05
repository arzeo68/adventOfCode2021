cmake_minimum_required(VERSION 3.5)
project(adventOfCode)

set(CMAKE_CXX_STANDARD 20)

add_executable(adventOfCode
        main.cpp
        header.hpp
        lib.cpp
        day02/dayO2.cpp)