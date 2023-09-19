cmake_minimum_required(VERSION 3.24)
project(Strings___Pointers C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Strings___Pointers
        lab6.c
        lab6strings.c
        lab6strings.h)
