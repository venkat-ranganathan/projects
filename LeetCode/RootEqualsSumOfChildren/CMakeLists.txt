cmake_minimum_required(VERSION 3.24)
project(RootEqualsSumOfChildren C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(RootEqualsSumOfChildren
        binaryTree.h binaryTree.c)
