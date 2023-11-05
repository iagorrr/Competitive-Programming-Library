#include "equals.cpp"
#include "template-line.cpp"
#include "template-point.cpp"

template <typename T>
struct Segment {
  Point<T> A, B;

  Segment(const Point<T> &a, const Point<T> &b)
    : A(a), B(b) {}

  /*
   * Verify if a given point P belongs to the segment,
   * considering that P belongs to the line defined with A
   * and B
   */
  bool contains(const Point<T> &P) const {
    return equals(A.x, B.x)
             ? min(A.y, B.y) <= P.y and P.y <= max(A.y, B.y)
             : min(A.x, B.x) <= P.x and
                 P.x <= max(A.x, B.x);
  }

  /*
   * Verify if P belongs to the segment AB,
   * even if P don't belong to the line defined with A and B
   * */
  bool contains2(const Point<T> &P) const {
    double dAB = dist(A, B), dAP = dist(A, P),
           dPB = dist(P, B);
    return equals(dAP + dPB, dAB);
  }

  /*
   * Find the closest point in P that belongs to the segment
   * */
  Point<T> closest(const Point<T> &P) {
    Line<T> r(A, B);
    auto Q = r.closest(P);

    if (this->contains(Q)) return Q;

    auto distA = P.distance(A);
    auto distB = P.distance(B);

    return distA <= distB ? A : B;
  }

  double distToClosest(const Point<T> &P) {
    return closest(P).distance(P);
  }
};
