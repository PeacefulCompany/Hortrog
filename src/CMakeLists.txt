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

FILE(GLOB_RECURSE LIB_FILES
    *.cpp
)

FOREACH(item ${LIB_FILES})
  IF(${item} MATCHES "main.cpp")
    LIST(REMOVE_ITEM LIB_FILES ${item})
  ENDIF(${item} MATCHES "main.cpp")
ENDFOREACH(item)
MESSAGE(STATUS "${LIB_FILES}")

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
add_library(${CMAKE_PROJECT_NAME}_lib ${LIB_FILES})
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE .)
target_include_directories(${CMAKE_PROJECT_NAME}_lib PUBLIC .)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE sfml-graphics)
target_link_libraries(${CMAKE_PROJECT_NAME}_lib PUBLIC sfml-graphics)