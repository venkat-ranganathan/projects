cmake_minimum_required(VERSION 3.24)
project(Functions C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Functions
        functions.c
        functions.h)
