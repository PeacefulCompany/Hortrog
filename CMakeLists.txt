cmake_minimum_required(VERSION 3.16)
project(COS214_FinalProject LANGUAGES CXX)

# --- PROJECT-WIDE CONFIGURATION ---
set(FETCHCONTENT_QUIET FALSE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(BUILD_SHARED_LIBS OFF)


# --- PROJECT SETUP ---
# Name of the executable target
set(BINARY ${CMAKE_PROJECT_NAME})

# Name of the compiled library
set(LIBRARY ${CMAKE_PROJECT_NAME}_lib)

# File containing the entry point(main)
set(ENTRY_POINT "main.cpp")

# Destination folder for Doxygen docs
set(DOCS_DOXYGEN "doc_doxygen")


set(FETCHCONTENT_QUIET FALSE)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)

# --- GENERATE DOCUMENTATION ---
# Source: https://vicrucann.github.io/tutorials/quick-cmake-doxygen/
find_package(Doxygen REQUIRED)

# set input and output files
set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

# request to configure the file
configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
message("Doxygen build started")

# note the option ALL which allows to build the docs together with the application
add_custom_target( doc_doxygen ALL
    COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Generating API documentation with Doxygen"
    VERBATIM )