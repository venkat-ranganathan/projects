cmake_minimum_required(VERSION 3.24)
project(pointerStructure C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(pointerStructure
        pointerStructure.c
        pointerStructure.h)
