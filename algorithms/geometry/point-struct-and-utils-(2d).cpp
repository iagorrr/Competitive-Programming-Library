#include <bits/stdc++.h>
using namespace std;
using ld = long double;

struct point {
  ld x, y;
  int id;
  point(ld x = 0.0, ld y = 0.0, int id = -1) : x(x), y(y), id(id) {}

  point& operator+=(const point& t) {
    x += t.x;
    y += t.y;
    return *this;
  }
  point& operator-=(const point& t) {
    x -= t.x;
    y -= t.y;
    return *this;
  }
  point& operator*=(ld t) {
    x *= t;
    y *= t;
    return *this;
  }
  point& operator/=(ld t) {
    x /= t;
    y /= t;
    return *this;
  }
  point operator+(const point& t) const { return point(*this) += t; }
  point operator-(const point& t) const { return point(*this) -= t; }
  point operator*(ld t) const { return point(*this) *= t; }
  point operator/(ld t) const { return point(*this) /= t; }
};

ld dot(point& a, point& b) { return a.x * b.x + a.y * b.y; }

ld norm(point& a) { return dot(a, a); }

ld abs(point a) { return sqrt(norm(a)); }

ld proj(point a, point b) { return dot(a, b) / abs(b); }

ld angle(point a, point b) { return acos(dot(a, b) / abs(a) / abs(b)); }

ld cross(point a, point b) { return a.x * b.y - a.y * b.x; }
