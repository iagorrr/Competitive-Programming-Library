#pragma once
#include <bits/stdc++.h>
using namespace std;

using ld = long double;
template <typename T>
using Point = pair<T, T>;
#define x first
#define y second

const double EPS{1e-6};
const ld PI = acos(-1);

template <typename T>
bool equals(T a, T b) {
    if (std::is_floating_point<T>::value)
        return fabs(a - b) < EPS;
    else
        return a == b;
}

template <typename T>
bool equals(Point<T> a, Point<T> b) {
    if (std::is_floating_point<T>::value)
        return fabs(a.x - b.x) < EPS && fabs(a.y - b.y) < EPS;
    else
        return a == b;
}
