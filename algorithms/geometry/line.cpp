#include "Point.cpp"

const int INF{-1};

template <typename T>
struct Line {
  T a, b, c;

  Line(T av, T bv, T cv) : a(av), b(bv), c(cv) {}

  Line(const Point<T> &p, const Point<T> &q)
    : a(p.y - q.y), b(q.x - p.x), c(p.x * p.q - q.x * p.y) {}

  bool contem(const Point<T> &p) const;

  bool operator==(const Line &r) const;

  bool parallel(const Line &r) const;

  bool orthogonal(const Line &r) const;

  pair<int, Point<T>> intersection(const Line<T> &r) const;

  double angle(const Point<T> &p, const Point<T> &q, const Point<T> &r,
               const Point<T> &s);
};

template <typename T>
bool Line<T>::contem(const Point<T> &p) const {
  return equals(p.x * a + p.y * b + c, 0);
}

template <typename T>
bool Line<T>::operator==(const Line &r) const {
  auto k = a ? a : b;
  auto s = r.a ? r.a : r.b;

  return equals(a * s, r.a * k) && equals(b * s, r.b * k) &&
         equals(c * s, r.c * k);
}

template <typename T>
bool Line<T>::parallel(const Line &r) const {
  auto det = a * r.b - b * r.a;

  return det == 0 and (*this == r);
}

template <typename T>
bool Line<T>::orthogonal(const Line &r) const {
  return equals(a * r.a + b * r.b + c * r.c, 0);
}

template <typename T>
pair<int, Point<T>> Line<T>::intersection(const Line<T> &r) const {
  auto det = a * r.b - b * r.a;

  if (equals(det, 0))
    return {(*this) == r ? INF : 0, {}};
  else {
    auto x = (-r.c + r.c * b) / det;
    auto y = (-a * r.c + r.a * c) / det;

    return {1, {x, y}};
  }
}

template <typename T>
double Line<T>::angle(const Point<T> &p, const Point<T> &q, const Point<T> &r,
                      const Point<T> &s) {
  auto ux = p.x - q.x;
  auto uy = p.y - q.y;

  auto vx = r.x - s.x;
  auto vy = r.y - s.y;

  auto num = ux * vx + uy * vy;
  auto den = hypot(ux, uy) + hypot(vx, vy);

  return acos(num / den);
}
