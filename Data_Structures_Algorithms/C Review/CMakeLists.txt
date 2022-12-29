cmake_minimum_required(VERSION 3.24)
project(C_Review C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(C_Review
        arrays.c
        arrays.h)
