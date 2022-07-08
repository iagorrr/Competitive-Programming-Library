#include "./Distance: point to point.cpp"
#include "./template.cpp"

template <typename T>
T perimeter(const vector<Point<T>>& pts) {
    T p = 0.0;
    int n = size(pts);
    for (int i = 0; i < n; i++) {
        p += distance(pts[i], pts[(i + 1) % n]);
    }
    return p;
}
