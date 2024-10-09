#include "../Contest/template.cpp"
#include "./Determinant.cpp"
#include "./template.cpp"

template <typename T>
vector<Point<T>> convexHull(vector<Point<T>> pts) {
  if (len(pts) <= 1) return pts;
  sort(all(pts));
  vector<Point<T>> h(len(pts) + 1);
  int s = 0, t = 0;
  for (int it = 2; it--; s = --t, reverse(all(pts)))
    for (Point<T> p : pts) {
      while (t >= s + 2 && determinant(h[t - 2], h[t - 1], p) <= 0) t--;
      h[t++] = p;
    }
  return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

template <typename T>
vector<Point<T>> convexHull2(vector<Point<T>> pts) {
  int n = len(pts);
  sort(pts.begin(), pts.end());
  vector<Point<T>> l, u;
  for (int i = 0; i < n; i++) {
    while (len(l) >= 2 &&
           determinant(l[len(l) - 1], l[len(l) - 2], pts[i]) < 0) {
      l.pop_back();
    }
    l.push_back(pts[i]);
  }

  for (int i = n - 1; ~i; --i) {
    while (len(u) >= 2 &&
           determinant(u[len(u) - 1], u[len(u) - 2], pts[i]) < 0) {
      u.pop_back();
    }
    u.push_back(pts[i]);
  }
  u.pop_back(), l.pop_back();
  u.reserve(len(u) + len(l));
  u.insert(u.end(), all(l));
  return u;
}
