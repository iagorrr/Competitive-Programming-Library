#include "./template.cpp"

template <typename T>
ld area(const vector<Point<T>>& pts) {
    ld a = 0.0;
    int n = size(pts);
    for (int i = 0; i < n; i++) {
        a += pts[i].x * pts[(i + 1) % n].y;
        a -= pts[i].y * pts[(i + 1) % n].x;
    }
    return fabs(a) / (ld)2;
}
