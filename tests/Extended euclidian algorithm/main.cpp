#include <assert.h>

#include <iostream>
#include <numeric>
#include <optional>

#include "../../content/Math/Extended Euclidian algorithm.cpp"

template <typename T>
void test(T a, T b, std::optional<T> g = std::nullopt) {
  if (!g) *g = std::gcd(a, b);
  auto [g2, x, y] = extGcd(a, b);
  assert(g2 == *g and a * x + b * y == g2);
}

int main() {
  test(0, 0, std::optional<int>{0});

  test(1071, 462);

  test(1234567890123456789LL, 987654321098765432LL);

  // brute force it !
  const int mx = mx;
  for (int a = -mx; a <= mx; a++)
    for (int b = -mx; b <= mx; b++) test(a, b);

  return 0;
}
