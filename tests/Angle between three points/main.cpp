#include <bits/stdc++.h>

#include "../../content/Geometry/Angle between three points.cpp"

template <typename T>
void test(Point<T> p, Point<T> a, Point<T> b, ld expected) {
  assert(equals(angle(p, a, b), expected));
}
int32_t main() {
  // 90 degrees
  test<ld>({0, 0}, {0, 100}, {100, 0}, 1.570796);

  // 180 degrees
  test<ld>({0, 0}, {-100, 0}, {100, 0}, 3.141593);

  // 45 degrees
  test<ld>({0, 0}, {100, 100}, {100, 0}, 0.7853982);
}
