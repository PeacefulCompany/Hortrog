# Name of the executable target
set(BINARY ${CMAKE_PROJECT_NAME})

# Name of the compiled library
set(LIBRARY ${CMAKE_PROJECT_NAME}_lib)

# File containing the entry point(main)
set(ENTRY_POINT "main.cpp")

# --- FETCH DEPENDENCIES ---
include(FetchContent)
FetchContent_Declare(
  SFML
  GIT_REPOSITORY https://github.com/SFML/SFML
  GIT_TAG        2.6.0
)
FetchContent_MakeAvailable(SFML)

# --- CONFIGURE SOURCE FILES ---
file(GLOB_RECURSE SOURCES_BIN *.cpp)
file(GLOB_RECURSE SOURCES_LIB *.cpp)

FOREACH(item ${SOURCES_LIB})
  IF(${item} MATCHES ${ENTRY_POINT})
    LIST(REMOVE_ITEM SOURCES_LIB ${item})
  ENDIF(${item} MATCHES ${ENTRY_POINT})
ENDFOREACH(item)
MESSAGE(STATUS "${SOURCES_LIB}")

# --- CONFIGURE OUTPUT TARGETS ---
add_executable(${BINARY} ${SOURCES_BIN})
target_include_directories(${BINARY} PRIVATE .)
target_link_libraries(${BINARY} PRIVATE sfml-graphics)

add_library(${LIBRARY} ${SOURCES_LIB})
target_include_directories(${LIBRARY} PUBLIC .)
target_link_libraries(${LIBRARY} PUBLIC sfml-graphics)