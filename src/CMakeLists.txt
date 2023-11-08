# --- CONFIGURE SOURCE FILES ---
file(GLOB_RECURSE SOURCES_LIB
  billing/*.cpp
  core/*.cpp
  customer/*.cpp
  floor/*.cpp
  menu/*.cpp
  order/*.cpp
  resource/*.cpp
  staff/*.cpp
  subsystem/*.cpp
)

file(GLOB_RECURSE SOURCES_BIN
  demo/*.cpp
)


# --- CONFIGURE OUTPUT TARGETS ---
add_library(${LIBRARY} ${SOURCES_LIB})
target_include_directories(${LIBRARY}
  PUBLIC .
  PRIVATE ${DIR_VENDOR}
)

add_executable(${BINARY} main.cpp ${SOURCES_BIN})
target_link_libraries(${BINARY} ${LIBRARY})
target_include_directories(${BINARY}
  PRIVATE .
  PRIVATE ${DIR_VENDOR}
)
add_dependencies(${BINARY} assets)
