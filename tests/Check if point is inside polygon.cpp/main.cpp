#include <bits/stdc++.h>

#include "../../content/Geometry/Check if point is inside polygon.cpp"

template <typename T>
void test(vector<Point<T>> pts, Point<T> p, bool expected) {
  assert(contains(pts, p) == expected);
}

void test_square_on_half() {
  // regular square, on vertices
  vector<Point<ld>> square = {{0, 0}, {0, 10}, {10, 10}, {10, 0}};
  // inside
  test<ld>(square, {1, 1}, true);
  test<ld>(square, {5, 5}, true);
  // in some edge
  test<ld>(square, {0, 1}, false);
  test<ld>(square, {0, 9}, false);
  test<ld>(square, {1, 0}, false);
  test<ld>(square, {9, 0}, false);
  // in some vertex
  test<ld>(square, {0, 0}, false);
  test<ld>(square, {0, 10}, false);
  test<ld>(square, {10, 10}, false);
  test<ld>(square, {10, 0}, false);
}
int32_t main() { test_square_on_half(); }
