cmake_minimum_required(VERSION 3.10)

project("gtest")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

enable_testing()

add_subdirectory(googletest)

add_library(vowel_lib vowel_lib/count_vowels.cpp)

add_executable(main_app main.cpp)
target_link_libraries(main_app vowel_lib)

add_executable(test_app test.cpp)
target_link_libraries(test_app gtest_main vowel_lib)