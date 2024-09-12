#pragma once
#include "../Contest/template.cpp"
#include "./Area: polygon.cpp"
#include "./template.cpp"

template <typename T>
pair<ll, ll> latticePoints(const vector<Point<T>> &pts) {
  ll bounds = pts.size();
  int n = pts.size();
  for (int i = 0; i < n; i++) {
    ll deltax = (pts[i].x - pts[(i + 1) % n].x);
    ll deltay = (pts[i].y - pts[(i + 1) % n].y);
    bounds += abs(__gcd(deltax, deltay)) - 1;
  }

  ll a = area(pts);
  ll inside = a + 1 - bounds / 2ll;
  return {inside, bounds};
}
