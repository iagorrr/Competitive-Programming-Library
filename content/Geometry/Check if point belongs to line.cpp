#pragma once
#include "./Define line from two points.cpp"
#include "./template.cpp"

template <typename T>
bool lineContainsPoint(const Point<T>& r, const Point<T>& p,
                       const Point<T>& q) {
  auto [a, b, c] = defineLine(p, q);
  return equals((T)0, a * r.x + b * r.y + c);
}
