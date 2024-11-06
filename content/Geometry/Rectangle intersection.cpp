/*
   Assumes that the points P, Q that define
   a rectangle are the bottom-left and top-right
   corner, and also that the sides are parallel to the axis.
 */
#pragma once
#include "../Contest/template.cpp"
#include "./Point.cpp"

template <typename T>
optional<pair<Point<T>, Point<T>>> rectangleIntersection(
    const pair<Point<T>, Point<T>> &r1, const pair<Point<T>, Point<T>> &r2) {
    assert(r1.first.x < r1.second.x && r1.first.y < r1.second.y);
    assert(r2.first.x < r2.second.x && r2.first.y < r2.second.y);
    T x1 = max(r1.first.x, r2.first.x);
    T x2 = min(r1.second.x, r2.second.x);

    T y1 = max(r1.first.y, r2.first.y);
    T y2 = min(r1.second.y, r2.second.y);
    if (x1 >= x2 or y1 >= y2) return nullopt;
    return pair<Point<T>, Point<T>>{{x1, y1}, {x2, y2}};
}
