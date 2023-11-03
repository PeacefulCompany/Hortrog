# Fetches and configures Google Testing Framework
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest
  GIT_TAG        v1.14.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

file(GLOB SOURCES_TESTS *.cpp)

foreach(item ${SOURCES_TESTS})
  get_filename_component(TEST_NAME ${item} NAME_WE)
  message(STATUS "${TEST_NAME}")

  add_executable(${TEST_NAME} ${item})
  target_link_libraries(${TEST_NAME}
  PRIVATE
  GTest::GTest
  ${LIBRARY})

  add_test(${TEST_NAME} ${TEST_NAME})
endforeach(item)
