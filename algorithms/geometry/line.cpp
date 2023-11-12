#include <bits/stdc++.h>

#include "point-struct-and-utils.cpp"
using namespace std;

struct line {
  ld a, b, c;
};

// the answer is stored in the third parameter (pass by
// reference)
void pointsToLine(const point &p1, const point &p2,
                  line &l) {
  if (fabs(p1.x - p2.x) < EPS)
    // vertical line
    l = {1.0, 0.0, -p1.x};
  // default values
  else
    l = {-(ld)(p1.y - p2.y) / (p1.x - p2.x), 1.0,
         -(ld)(l.a * p1.x) - p1.y};
}
