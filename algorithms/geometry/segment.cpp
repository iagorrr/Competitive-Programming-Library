#include "Line.cpp"
#include "Point.cpp"
#include "equals.cpp"

template <typename T>
struct segment {
  Point<T> A, B;

  bool contains(const Point<T> &P) const;

  Point<T> closest(const Point<T> &p) const;
};

template <typename T>
bool segment<T>::contains(const Point<T> &P) const {
  // verifica se P está contido na reta
  double dAB = Point<T>::dist(A, B), dAP = Point<T>::dist(A, P),
         dPB = Point<T>::dist(P, B);

  return equals(dAP + dPB, dAB);
}

template <typename T>
Point<T> segment<T>::closest(const Point<T> &P) const {
  Line<T> R(A, B);
  auto Q = R.closest(P);

  if (this->contains(Q)) return Q;

  auto distA = Point<T>::dist(P, A);
  auto distB = Point<T>::dist(P, B);

  if (distA <= distB)
    return A;
  else
    return B;
}
