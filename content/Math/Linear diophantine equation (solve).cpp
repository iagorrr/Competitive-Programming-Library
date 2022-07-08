/*8<
  @Description:
    Finds a solution for $ax + by = c$, where $a$, $b$, $c$, are given and
    $x$ and $y$ unknown.

  @Time: $O(\log{min(a,b)})$
>8*/
#pragma once
#include "../Contest/template.cpp"
#include "./Extended Euclidian algorithm.cpp"

template <typename T>
optional<pair<T, T>> diophantineEquationSolution(T a, T b, T c) {
    if (a == 0 and b == 0) {
        if (c)
            return nullopt;
        else
            return pair<T, T>{(T)0, (T)0};
    }

    auto [g, x0, y0] = extGcd(a < 0 ? a * -1 : a, b < 0 ? b * -1 : b);

    if (c % g) return nullopt;

    x0 *= c / g, y0 *= c / g;

    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;

    pair<T, T> ret;
    ret.first = x0, ret.second = y0;
    return ret;
}
