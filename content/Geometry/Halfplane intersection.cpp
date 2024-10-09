#pragma once
#include "./Point.cpp"
#include "./template.cpp"

// Basic half-plane struct.
struct Halfplane {
  // 'p' is a passing point of the line and 'pq' is the direction vector of the
  // line.
  Point<ld> p, pq;
  long double angle;

  Halfplane() {}
  Halfplane(const Point<ld>& a, const Point<ld>& b) : p(a), pq(b - a) {
    angle = atan2l(pq.y, pq.x);
  }

  // Check if point 'r' is outside this half-plane.
  // Every half-plane allows the region to the LEFT of its line.
  bool out(const Point<ld>& r) { return cross(pq, r - p) < -EPS; }

  // Intersection point of the lines of two half-planes. It is assumed they're
  // never parallel.
  friend Point<ld> inter(const Halfplane& s, const Halfplane& t) {
    long double alpha = cross((t.p - s.p), t.pq) / cross(s.pq, t.pq);
    return s.p + (s.pq * alpha);
  }
};

// Actual algorithm
// receive it by reference if don't care messing with it
vector<Point<ld>> hp_intersect(vector<Halfplane> H) {
  const ld inf = 2e6;

  Point<ld> box[4] = {// Bounding box in CCW order
                      Point<ld>(inf, inf), Point<ld>(-inf, inf),
                      Point<ld>(-inf, -inf), Point<ld>(inf, -inf)};

  for (int i = 0; i < 4; i++) {  // Add bounding box half-planes.
    Halfplane aux(box[i], box[(i + 1) % 4]);
    H.push_back(aux);
  }

  // Sort by angle and start algorithm
  sort(H.begin(), H.end(), [&](const Halfplane& a, const Halfplane& b) {
    return a.angle < b.angle;
  });
  deque<Halfplane> dq;
  int len = 0;
  for (int i = 0; i < int(H.size()); i++) {
    // Remove from the back of the deque while last half-plane is redundant
    while (len > 1 && H[i].out(inter(dq[len - 1], dq[len - 2]))) {
      dq.pop_back();
      --len;
    }

    // Remove from the front of the deque while first half-plane is redundant
    while (len > 1 && H[i].out(inter(dq[0], dq[1]))) {
      dq.pop_front();
      --len;
    }

    // Special case check: Parallel half-planes
    if (len > 0 && fabsl(cross(H[i].pq, dq[len - 1].pq)) < EPS) {
      // Opposite parallel half-planes that ended up checked against each other.
      if (dot(H[i].pq, dq[len - 1].pq) < 0.0) return vector<Point<ld>>();

      // Same direction half-plane: keep only the leftmost half-plane.
      if (H[i].out(dq[len - 1].p)) {
        dq.pop_back();
        --len;
      } else
        continue;
    }

    // Add new half-plane
    dq.push_back(H[i]);
    ++len;
  }

  // Final cleanup: Check half-planes at the front against the back and
  // vice-versa
  while (len > 2 && dq[0].out(inter(dq[len - 1], dq[len - 2]))) {
    dq.pop_back();
    --len;
  }

  while (len > 2 && dq[len - 1].out(inter(dq[0], dq[1]))) {
    dq.pop_front();
    --len;
  }

  // Report empty intersection if necessary
  if (len < 3) return vector<Point<ld>>();

  // Reconstruct the convex polygon from the remaining half-planes.
  vector<Point<ld>> ret(len);
  for (int i = 0; i + 1 < len; i++) {
    ret[i] = inter(dq[i], dq[i + 1]);
  }
  ret.back() = inter(dq[len - 1], dq[0]);
  return ret;
}
