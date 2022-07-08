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

include(GoogleTest)

# extended-euclidian-algorithm
add_executable(
        test_extended_euclidian_algorithm
        ./tests/extended_euclidian_algorithm/test.cc
)
target_link_libraries (
        test_extended_euclidian_algorithm
        GTest::gtest_main
)
gtest_discover_tests(test_extended_euclidian_algorithm)

# linear_diophantine_equation_solve
add_executable(
        test_linear_diophantine_equation_solve
        ./tests/linear-diophantine-equaiton-solve/test.cc
)
target_link_libraries (
        test_linear_diophantine_equation_solve
        GTest::gtest_main
)
gtest_discover_tests(test_linear_diophantine_equation_solve)

# count_mandatory_nodes_on_single_path
add_executable(
        test_count_mandatory_nodes_on_single_path
        ./tests/count-mandatory-nodes-on-single-path/test.cc
)
target_link_libraries (
        test_count_mandatory_nodes_on_single_path
        GTest::gtest_main
)
gtest_discover_tests(test_count_mandatory_nodes_on_single_path)

# Z-Function build
add_executable(
        test_z_function_build
        ./tests/z-function-build/test.cc
)
target_link_libraries (
        test_z_function_build
        GTest::gtest_main
)
gtest_discover_tests(test_z_function_build)

# z-function-pattern-matching
add_executable(
        test_z_function_pattern_matching
        ./tests/z-function-pattern-matching/test.cc
)
target_link_libraries (
        test_z_function_pattern_matching
        GTest::gtest_main
)
gtest_discover_tests(test_z_function_pattern_matching)


# z-function-find-period
add_executable(
        test_z_function_find_period
        ./tests/z-function-find-period/test.cc
)
target_link_libraries (
        test_z_function_find_period
        GTest::gtest_main
)
gtest_discover_tests(test_z_function_find_period)

# z-function-approximate-pattern-matching
add_executable(
        test_z_function_approximate_pattern_matching
        ./tests/z-function-approximate-pattern-matching/test.cc
)
target_link_libraries (
        test_z_function_approximate_pattern_matching
        GTest::gtest_main
)
gtest_discover_tests(test_z_function_approximate_pattern_matching)
