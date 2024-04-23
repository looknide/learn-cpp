cmake_minimum_required(VERSION 3.24)
project(project2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(project2
        hello.cpp
        hello.h
        main.cpp)
