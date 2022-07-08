#include <bits/stdc++.h>

#include "../../content/Contest/template.cpp"
#include "../../content/Geometry/Left of polygon cut.cpp"

template <typename T>
void test(vector<Point<T>> pts, Point<T> a, Point<T> b,
          vector<Point<T>> exptected) {
    auto ret = leftOfPolygonCut(pts, a, b);
    bool ok = true;
    for (auto ei : exptected) {
        bool cur = false;
        for (auto ri : ret) {
            cur |= equals(ei, ri);
        }
        ok &= cur;
    }

    for (auto ri : ret) {
        bool cur = false;
        for (auto ei : exptected) {
            cur |= equals(ei, ri);
        }
        ok &= cur;
    }
    assert(ok);
}

void test_square_on_half() {
    // regular square, on vertices
    vector<Point<ld>> square = {{0, 0}, {0, 10}, {10, 10}, {10, 0}};
    Point<ld> a{3, 0};
    Point<ld> b{3, 10};
    vector<Point<ld>> exptected{{0, 0}, {0, 10}, {3, 10}, {3, 0}};
    test<ld>(square, a, b, exptected);
}

void test_triangle() {
    // regular square, on vertices
    vector<Point<ld>> triangle = {{0, 0}, {3, 3}, {6, 0}};
    Point<ld> a{1, -1};
    Point<ld> b{5, 3};
    vector<Point<ld>> exptected{{0, 0}, {3, 3}, {2, 0}, {4, 2}};
    test<ld>(triangle, a, b, exptected);
}

void test_triangle_on_edge() {
    // regular square, on vertices
    vector<Point<ld>> triangle = {{0, 0}, {3, 3}, {6, 0}};
    Point<ld> a{-1, -1};
    Point<ld> b{4, 4};
    vector<Point<ld>> exptected{{0, 0}, {3, 3}};
    test<ld>(triangle, a, b, exptected);
}

int32_t main() {
    test_square_on_half();
    test_triangle();
    test_triangle_on_edge();
}
