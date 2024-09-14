#pragma once
#include "./template.cpp"

template <typename T>
T determinant(const Point<T>& p, const Point<T>& q, const Point<T>& r) {
  return (p.x * q.y + p.y * r.x + q.x * r.y) -
         (r.x * q.y + r.y * p.x + q.x * p.y);
}
