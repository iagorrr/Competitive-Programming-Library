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
