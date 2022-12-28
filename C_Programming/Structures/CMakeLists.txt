cmake_minimum_required(VERSION 3.24)
project(Structures C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Structures
        lab7.c
        lab7structures.c
        lab7structures.h)
