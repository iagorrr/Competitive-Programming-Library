#pragma once
#include "./template.cpp"

template <typename T>
T cross(const Point<T>& p, const Point<T>& q) {
  return p.x * q.y - p.y * q.x;
}
