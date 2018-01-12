project("glfew-examples")
cmake_minimum_required(VERSION 2.8)

SET(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "limited configs" FORCE)
set(CMAKE_C_FLAGS "-Wall")
set(CMAKE_C_FLAGS_DEBUG "-g3 -O0 -pg -DDEBUG")
set(CMAKE_C_FLAGS_RELEASE "-O2 -s -DNDEBUG -march=native")

add_subdirectory(glfw-simple-window)

