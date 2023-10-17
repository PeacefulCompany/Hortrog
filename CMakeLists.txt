cmake_minimum_required(VERSION 3.16)
project(COS214_FinalProject LANGUAGES CXX)

set(FETCHCONTENT_QUIET FALSE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Name of the executable target
set(BINARY ${CMAKE_PROJECT_NAME})

# Name of the compiled library
set(LIBRARY ${CMAKE_PROJECT_NAME}_lib)

# File containing the entry point(main)
set(ENTRY_POINT "main.cpp")

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)