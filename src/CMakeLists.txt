
# --- FETCH DEPENDENCIES ---
include(FetchContent)
FetchContent_Declare(
  SFML
  GIT_REPOSITORY https://github.com/SFML/SFML
  GIT_TAG        2.6.0
)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json
  GIT_TAG        v3.11.2
)
FetchContent_MakeAvailable(json)

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
target_link_libraries(${BINARY}
  PRIVATE sfml-graphics
  PRIVATE nlohmann_json::nlohmann_json
)
add_dependencies(${BINARY} assets)

add_library(${LIBRARY} ${SOURCES_LIB})
target_include_directories(${LIBRARY} PUBLIC .)
target_link_libraries(${LIBRARY}
  PUBLIC sfml-graphics
  PUBLIC nlohmann_json::nlohmann_json
)