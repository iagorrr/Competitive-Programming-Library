#include "../../content/Math/Linear diophantine equation (solve).cpp"

template <typename T>
void test(T a, T b, T c) {
  auto sol = diophantineEquationSolution(a, b, c);
  if (c % gcd(a, b))
    assert(!sol);
  else {
    auto [x, y] = *sol;
    assert(sol and a * x + b * y == c);
  }
}

int main() {
  // brute force
  const int mx = 100;
  for (int a = -mx; a <= mx; a++) {
    for (int b = -mx; b <= mx; b++) {
      for (int c = -mx; c <= mx; c++) {
        test(a, b, c);
      }
    }
  }
  return 0;
}
