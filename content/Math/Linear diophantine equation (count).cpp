/*8<
  @Description:
  @Time: $O(\log{min(a,b)})$
>8*/
#pragma once
#include "../Contest/template.cpp"
#include "./Extended Euclidian algorithm.cpp"
#include "./Linear diophantine equation (solve).cpp"

template <typename T>
T countSolutionsInRange(T a, T b, T c, T minX, T maxX, T minY, T maxY) {
    auto ss = [&](T &x, T &y, T a, T b, T cnt) { x += cnt * b, y -= cnt * a; };

    assert(a and b);

    auto sol = diophantineEquationSolution(a, b, c);
    if (!sol) return 0;

    auto [x, y] = *sol;
    auto g = get<0>(extGcd(a, b));
    a /= g;
    b /= g;

    int signA = a > 0 ? +1 : -1;
    int signB = b > 0 ? +1 : -1;

    ss(x, y, a, b, (minX - x) / b);
    if (x < minX) ss(x, y, a, b, signB);
    if (x > maxX) return 0;
    int lx1 = x;

    ss(x, y, a, b, (maxX - x) / b);
    if (x > maxX) ss(x, y, a, b, -signB);
    int rx1 = x;

    ss(x, y, a, b, -(minY - y) / a);
    if (y < minY) ss(x, y, a, b, -signA);
    if (y > maxY) return 0;
    int lx2 = x;

    ss(x, y, a, b, -(maxY - y) / a);
    if (y > maxY) ss(x, y, a, b, signA);
    int rx2 = x;

    if (lx2 > rx2) swap(lx2, rx2);
    int lx = max(lx1, lx2);
    int rx = min(rx1, rx2);

    if (lx > rx) return 0;
    return (rx - lx) / abs(b) + 1;
}
