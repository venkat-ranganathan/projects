cmake_minimum_required(VERSION 3.24)
project(projects)

set(CMAKE_CXX_STANDARD 14)

include_directories(C_Programming/Primes/)

add_executable(projects
        C_Programming/Primes/lab4.c
        C_Programming/Primes/lab4prime.c
        C_Programming/Primes/lab4prime.h)
