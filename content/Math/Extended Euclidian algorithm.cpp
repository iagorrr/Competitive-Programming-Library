/*8<
    @Description:
        Finds the gcd between $a$ and $b$ and $x$ and $y$ such that
        $ax + by = g$
    @Time:
        $O(\log{min(a,b)})$
    @Warning:
      If $ a = b = 0 $ then there is infity solutions, but $0$ is returned.
      Be careful about overflow.
>8*/

#pragma once
#include "../Contest/template.cpp"

template <typename T>
tuple<T, T, T> extGcd(T a, T b) {
    if (!b) return {a, 1, 0};
    auto [d, x1, y1] = extGcd(b, a % b);
    T x = y1, y = x1 - y1 * (a / b);
    return {d, x, y};
}
