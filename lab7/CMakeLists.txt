cmake_minimum_required(VERSION 3.26)

project(lab7)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED)

add_subdirectory("lib")

add_library(lab::game ALIAS game)

add_subdirectory("src")

enable_testing()
add_subdirectory("tests")