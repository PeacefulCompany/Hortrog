include(FetchContent)
FetchContent_Declare(
  SFML
  GIT_REPOSITORY https://github.com/SFML/SFML
  GIT_TAG        2.6.0
)
FetchContent_MakeAvailable(SFML)

file(GLOB_RECURSE SOURCES 
    *.cpp
)
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
add_library(${CMAKE_PROJECT_NAME}_lib ${SOURCES})
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE .)
target_include_directories(${CMAKE_PROJECT_NAME}_lib PUBLIC .)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE sfml-graphics)
target_link_libraries(${CMAKE_PROJECT_NAME}_lib PUBLIC sfml-graphics)