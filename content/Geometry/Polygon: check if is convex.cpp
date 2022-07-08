#include "./Determinant.cpp"
#include "./template.cpp"

template <typename T>
bool checkIfPolygonIsConvex(vector<Point<T>>& pts) {
    int n = size(pts);
    if (n < 3) return false;
    int l, g, e;
    l = g = e = 0;
    for (int i = 0; i < n; i++) {
        auto d = determinant(pts[i], pts[(i + 1) % n], pts[(i + 2) % n]);
        d ? (d > 0 ? g++ : l++) : e++;
    }
    return l == n or g == n;
}
