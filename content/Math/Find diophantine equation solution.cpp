/*8<
  @Title: Find diophantine equation solution
  @Description:
    Given $a$ $b$, $c$ finds the solution to the
    equation $ax + by = c$, the result will be
    stored in the reference variables $x0$ and
    $y0$.
  @Time: $O(\log{min(a,b)})$
>8*/

template <typename T>
tuple<T, T, T> ext_gcd(T a, T b) {
  if (b == 0) return {a, 1, 0};

  auto [d, x1, y1] = ext_gcd(b, a % b);

  return {d, y1, x1 - y1 * (a / b)};
}

template <typename T>
tuple<bool, T, T> find_any_solution(T a, T b,
                                    T c) {
  assert(a != 0 or b != 0);
#warning Be careful with overflow, use __int128 if needed !

  auto [d, x0, y0] =
      ext_gcd(a < 0 ? -a : a, b < 0 ? -b : b);

  if (c % d) return {false, 0, 0};

  x0 *= c / d;
  y0 *= c / d;
  if (a < 0) x0 = -x0;
  if (b < 0) y0 = -y0;

  return {true, x0, y0};
}
