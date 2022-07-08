/*8<
  @Description: checks if the point $p$ is inside the polygon with vertices in
  $pts$, works for both convex and concave polygons.
  @Warning: If not working for integers points try to use long double.
>8*/
#pragma once
#include "./Angle between three points.cpp"
#include "./Check if point belongs to segment.cpp"
#include "./Determinant.cpp"
#include "./template.cpp"

template <typename T>
bool contains(const vector<Point<T>>& pts, const Point<T>& p) {
    int n = size(pts);
    if (n < 3) return false;  // may treat it appart
    T sum = 0.0;
    for (int i = 0; i < n; i++) {
        auto d = determinant(p, pts[i], pts[(i + 1) % n]);
        auto a = angle(p, pts[i], pts[(i + 1) % n]);
        sum += d > 0 ? a : (d < 0 ? -a : 0);
    }
    return equals(fabs(sum), 2 * PI);
}

// 0: outside, 1: inside, 2: boundary
template <class P>
int pointInPolygon(const vector<P>& pts, const P& p) {
    if (contains(pts, p)) return 1;
    int n = size(pts);
    for (int i = 0; i < n; i++) {
        if (segmentContainsPoint(p, pts[i], pts[(i + 1) % n])) {
            return 2;
        }
    }
    return 0;
}
