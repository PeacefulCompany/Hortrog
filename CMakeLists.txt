cmake_minimum_required(VERSION 3.16)
project(COS214_FinalProject LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(FETCHCONTENT_QUIET FALSE)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)