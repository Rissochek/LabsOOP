cmake_minimum_required(VERSION 3.10)

project("gtest")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(googletest)

add_library(CustomAllocator libs/Allocator_lib/Allocator.cpp)

add_executable(main_app main.cpp)
target_link_libraries(main_app CustomAllocator)

add_executable(test_app tests.cpp)
target_link_libraries(test_app gtest_main CustomAllocator)
