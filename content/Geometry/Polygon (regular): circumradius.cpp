#include "./Distance: point to point.cpp"
#include "./template.cpp"

template <typename T>
ld circumradius(const vector<Point<T>>& pts) {
    auto s = distance(pts[0], pts[1]);
    int n = size(pts);
    return (s / 2.0) * (1.0 / sin(PI / (ld)n));
}
