
using ld = long double;

template <typename T = ld>
struct Point {
  T x, y;
  bool is_port;
};

template <typename T = ld>
bool operator==(const Point<T> &a, const Point<T> &b) {
  return a.x == b.x and a.y == b.y;
}

template <typename T = ld>
struct Segment {
  Point<T> p1, p2;
};

template <typename T>
int orientation(Point<T> p, Point<T> q, Point<T> r) {
  int val =
    (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
  // TODO: if it's a float must use other way to compare
  if (val == 0)
    return 0;  // colinear
  else if (val > 0)
    return 1;  // clockwise
  else
    return 2;  // counterclockwise
}

template <typename T>
bool do_segment_intersect(Segment<T> s1, Segment<T> s2) {
  int o1 = orientation(s1.p1, s1.p2, s2.p1);
  int o2 = orientation(s1.p1, s1.p2, s2.p2);

  int o3 = orientation(s2.p1, s2.p2, s1.p1);
  int o4 = orientation(s2.p1, s2.p2, s1.p2);

  return (o1 != o2 and o3 != o4) or (o1 == 0 and o3 == 0) or
         (o2 == 0 and o4 == 0);
}
