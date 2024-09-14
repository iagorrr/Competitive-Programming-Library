#include "./template.cpp"

template <class P>
bool segmentContainsPoint(const P& p, const P& a, const P& b) {
  auto xmin = min(a.x, b.x);
  auto xmax = max(a.x, b.x);

  auto ymin = min(a.y, b.y);
  auto ymax = max(a.y, b.y);

  if (p.x < xmin or p.x > xmax or p.y < ymin or p.y > ymax) return false;
  return equals((p.y - a.y) * (b.x - a.x), (p.x - a.x) * (b.y - a.y));
}
