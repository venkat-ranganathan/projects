cmake_minimum_required(VERSION 3.24)
project(Structures C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Functions
        lab2.c
        lab2functions.c
        lab2.h)
