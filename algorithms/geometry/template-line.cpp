#include "template-point.cpp"

template <typename T>
struct Line {
  T a, b, c;

  Line(T av, T bv, T cv) : a(av), b(bv), c(cv) {}

  Line(const Point<T> &P, const Point<T> &Q)
    : a(P.y - Q.y),
      b(Q.x - P.x),
      c(P.x * Q.y - Q.x * P.y) {}

  // verify if a point belongs to the line
  bool contains(const Point<T> &P) {
    return equals(a * P.x + b * P.y + c, 0);
  }

  // shortest distance between P and a point Q that belongs
  // to this line
  double distance(const Point<T> &P) const {
    return fabs(a * P.x + b * P.y + c) / hypot(a, b);
  }

  // the closest point in this line to the given point
  Point<T> closest(const Point<T> &P) const {
    auto den = (a * a) + (b * b);

    auto x = (b * (b * P.x - a * P.y) - a * c) / den;
    auto y = (a * (-b * P.x + a * P.y) - b * c) / den;

    return Point<T>{x, y};
  }
};
