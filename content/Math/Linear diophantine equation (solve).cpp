/*8<
  @Description:
    Finds a solution for $ax + by = c$, where $a$, $b$, $c$, are given and
    $x$ and $y$ unknown.

  @Time: O(\log{min(a,b)})
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
      return pair<T, T>{0, 0};
  }

  auto [g, x0, y0] = extGcd(abs(a), abs(b));

  if (c % g) return nullopt;

  x0 *= c / g, y0 *= c / g;

  if (a < 0) x0 = -x0;
  if (b < 0) y0 = -y0;
  return pair<T, T>{x0, y0};
}
