#pragma once
#include "./template.cpp"

template <typename T>
inline tuple<T, T, T> defineLine(const Point<T>& p, const Point<T>& q) {
  return {p.y - q.y, q.x - p.x, cross(p, q)};
}
