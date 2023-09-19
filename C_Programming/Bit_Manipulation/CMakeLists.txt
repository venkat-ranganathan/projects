# This file handles building each task as sub-project.
#
# Each task becomes an independent project in which you can experiment.
#
# Tasks are added as separate sub-projects so as compilation errors in
# one task don't affect another task.


project(Strings___Pointers)

set(CMAKE_CXX_STANDARD C)


# Add tasks subprojects
include(cmake/utils.cmake)
add_subprojects(${CMAKE_SOURCE_DIR})