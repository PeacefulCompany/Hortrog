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

# Function that automatically adds and links a test
function(add_unit_test name)
    add_executable(${name} ${ARGN})
    target_link_libraries(${name}
    PRIVATE
    GTest::GTest
    ${CMAKE_PROJECT_NAME}_lib)

    add_test(${name} ${name})
endfunction()

# Specify all tests here
add_unit_test(multiply_test multiply_test.cpp)