cmake_minimum_required(VERSION 3.16)
project(COS214_FinalProject LANGUAGES CXX)

# --- CMAKE-SPECIFIC CONFIGURATION ---
set(FETCHCONTENT_QUIET FALSE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(BUILD_SHARED_LIBS OFF)

# --- BUILD OPTIONS ---
option(BUILD_TESTS "Build Tests" ON)
option(BUILD_DOCS "Build Documentation" ON)
option(BUILD_EXE "Build Executable" ON)

# --- PROJECT CONFIGURATION ---
set(BINARY ${CMAKE_PROJECT_NAME})
set(LIBRARY ${CMAKE_PROJECT_NAME}_lib)

set(ENTRY_POINT "main.cpp")
set(DOCS_DOXYGEN "docs")
set(DIR_ASSETS ${CMAKE_SOURCE_DIR}/assets)
set(DIR_VENDOR ${CMAKE_SOURCE_DIR}/vendor)

if(BUILD_TESTS)
    enable_testing()
endif()

# --- COPY ASSETS ---
add_custom_target(assets ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${DIR_ASSETS}
    ${CMAKE_CURRENT_BINARY_DIR}/src/assets
    COMMENT "Copying assets to build directory"
)

add_subdirectory(src)

if(BUILD_DOCS)
    add_subdirectory(docs)
endif()
if(BUILD_TESTS)
    add_subdirectory(tests)
endif()
