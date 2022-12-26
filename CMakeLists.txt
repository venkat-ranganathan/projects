cmake_minimum_required(VERSION 3.24)
project(projects)

set(CMAKE_CXX_STANDARD 14)

include_directories(C_Programming/Structures)

add_executable(projects
        C_Programming/Structures/lab7.c
        C_Programming/Structures/lab7.exe
        C_Programming/Structures/lab7structures.c
        C_Programming/Structures/lab7structures.exe
        C_Programming/Structures/lab7structures.h)
