#include "../../content/Contest/template.cpp"
#include "../../content/Geometry/Polygon (regular): circumradius.cpp"

template <typename T>
void test(vector<Point<T>> pts, T exptected) {
  auto ret = circumradius(pts);
  assert(equals(ret, exptected));
}

void test_square() {
  vector<Point<ld>> square{{0, 0}, {0, 4}, {4, 4}, {4, 0}};
  test(square, (ld)2.8284271247461903);
}
int32_t main() { test_square(); }
