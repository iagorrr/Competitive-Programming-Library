#include "../../content/Contest/template.cpp"
#include "../../content/Geometry/Polygon (regular): apothem.cpp"

template <typename T>
void test(vector<Point<T>> pts, T exptected) {
  auto ret = apothem(pts);
  assert(equals(ret, exptected));
}

void test_square() {
  vector<Point<ld>> square{{0, 0}, {0, 4}, {4, 4}, {4, 0}};
  test(square, (ld)2);
}
int32_t main() { test_square(); }
