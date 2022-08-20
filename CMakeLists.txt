cmake_minimum_required(VERSION 3.24.0)
project(tl-test)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_library(
    hotel
    src/question1/hotel.cpp
)
add_library(
    binary_tree_calculator
    src/question2/binary_tree_calculator.cpp
)

add_executable(
    question1
    src/question1/question1.cpp
)
target_link_libraries(
    question1
    hotel
)

add_executable(
    question2
    src/question2/question2.cpp
)
target_link_libraries(
    question2
    binary_tree_calculator
)

enable_testing()

add_executable(
    hotel_test
    src/question1/test/hotel_test.cpp
)
target_link_libraries(
    hotel_test
    GTest::gtest_main
)

add_executable(
    binary_tree_calculator_test
    src/question2/test/binary_tree_calculator_test.cpp
)
target_link_libraries(
    binary_tree_calculator_test
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(hotel_test)
gtest_discover_tests(binary_tree_calculator_test)