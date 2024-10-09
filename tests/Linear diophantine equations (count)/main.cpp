#include <iomanip>  // For std::setprecision
#include <iostream>

#include "../../content/Math/Linear diophantine equation (count).cpp"

void run_test(const char* name, bool (*test_func)()) {
  std::cout << "Running test: " << name << "... ";
  if (test_func()) {
    std::cout << "PASSED" << std::endl;
  } else {
    std::cout << "FAILED" << std::endl;
  }
}

template <typename T>
void test(T a, T b, T c, T minX, T maxX, T minY, T maxY, T expected) {
  assert(countSolutionsInRange(a, b, c, minX, maxX, minY, maxY) == expected);
}

void test_basic_functionality() {
  test(1, 2, 3, 0, 10, 0, 10, 2);
  test(2, 3, 5, -10, 10, -10, 10, 7);
}

void test_no_solutions() { return test(2, 4, 3, 0, 10, 0, 10, 0); }

void test_edge_cases() {
  test(1, 1, 1, 0, 1, 0, 1, 2);
  test(1, 1, 1, 0, 1, 1, 2, 1);
}

void test_negative_numbers() {
  test(-1, -2, -3, -10, 0, -10, 0, 0);
  test(-2, -3, -5, -10, 10, -10, 10, 7);
}

int main() {
  test_basic_functionality();
  test_no_solutions();
  test_edge_cases();
  test_negative_numbers();
  return 0;
}
