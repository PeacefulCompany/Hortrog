file(GLOB_RECURSE SOURCES 
    *.cpp
)
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
add_library(${CMAKE_PROJECT_NAME}_lib ${SOURCES})
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE .)
target_include_directories(${CMAKE_PROJECT_NAME}_lib PUBLIC .)
