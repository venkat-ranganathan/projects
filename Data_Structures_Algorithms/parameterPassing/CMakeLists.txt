cmake_minimum_required(VERSION 3.24)
project(parameterPassing C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(parameterPassing
        parameterPassing.c
        parameterPassing.h)
