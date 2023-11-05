template <typename T>
struct Point {
  T x, y;

  Point(T xv = 0, T yv = 0) : x(xv), y(yv) {}

  double distance(const Point<T> &P) const {
    return hypot(static_cast<double>(P.x - this->x),
                 static_cast<double>(P.y - this->y));
  }
};
