#include <cassert>

#include "../../content/Data Structures/2D Segment Tree/Point update query sum.cpp"

void test1() {
  int h = 10, w = 5;
  vector xs(h, vector<ll>(w));
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      ll x = (i - 1) * w + j;
      xs[i - 1][j - 1] = x;
    }
  }

  auto op = [](ll a, ll b) { return a + b; };
  SegmentTree2D<ll, op> seg(xs);

  auto getsum = [&](int lx, int rx, int ly, int ry) {
    ll ret = 0;
    for (int i = lx; i <= rx; i++) {
      for (int j = ly; j <= ry; j++) {
        ret = op(ret, xs[i][j]);
      }
    }
    return ret;
  };

  for (int lx = 0; lx < h; lx++) {
    for (int rx = lx; rx < h; rx++) {
      for (int ly = 0; ly < w; ly++) {
        for (int ry = ly; ry < w; ry++) {
          ll expected = getsum(lx, rx, ly, ry);
          ll got = seg.query(lx, rx, ly, ry);
          assert(expected == got);
        }
      }
    }
  }
}

void test2() {
  int h = 2, w = 2;
  vector<vector<ll>> xs{
      {12, 6},
      {4, 3},
  };

  auto op = [](ll a, ll b) { return gcd(a, b); };
  SegmentTree2D<ll, op> seg(xs);

  assert(seg.query(0, 0, 0, 1) == 6);
  assert(seg.query(0, 1, 0, 0) == 4);
  assert(seg.query(1, 1, 0, 1) == 1);
  assert(seg.query(1, 1, 0, 1) == 1);
  assert(seg.query(0, 1, 1, 1) == 3);
}

int32_t main() {
  test1();
  test2();
}
