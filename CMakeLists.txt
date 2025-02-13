cmake_minimum_required(VERSION 3.14)
project(competitive_programming_library)

# GoogleTest requires at least C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

# hello_test
add_executable(
  hello_test
  ./tests/hello_test.cc
)
target_link_libraries(
  hello_test
  GTest::gtest_main
)

# extended-euclidian-algorithm
add_executable(
        test_extended_euclidian_algorithm
        ./tests/extended_euclidian_algorithm/test.cc
)
target_link_libraries (
        test_extended_euclidian_algorithm
        GTest::gtest_main
)

# linear_diophantine_equation_solve
add_executable(
        test_linear_diophantine_equation_solve
        ./tests/linear-diophantine-equaiton-solve/test.cc
)
target_link_libraries (
        test_linear_diophantine_equation_solve
        GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(hello_test)
gtest_discover_tests(test_extended_euclidian_algorithm)
gtest_discover_tests(test_linear_diophantine_equation_solve)


