// Verifica se o ponto P pertence ao segmento de
// reta AB
const ld EPS = 1e-9;

template <typename T>
struct Point {
  T x, y;
  Point(T _x, T _y) : x(_x), y(_y) {}
};

template <typename T>
bool equals(const T a, const T b) {
  if (is_floating_point<T>) {
    return fabsl(a - b) <= EPS;
  }
  return a == b;
}

/*
   Verify if the segment AB contains point P
 */
template <typename T>
bool contains(const Point<T> &A,
              const Point<T> &B,
              const Point<T> &P) {
  auto xmin = min(A.x, B.x);
  auto xmax = max(A.x, B.x);
  auto ymin = min(A.y, B.y);
  auto ymax = max(A.y, B.y);

  if (P.x < xmin || P.x > xmax || P.y < ymin ||
      P.y > ymax)
    return false;

  return equals((P.y - A.y) * (B.x - A.x),
                (P.x - A.x) * (B.y - A.y));
}
