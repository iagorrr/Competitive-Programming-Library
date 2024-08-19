/*8<
  @Title:

    Max \& Min Check

  @Description:

    Returns the min/max value in range [l, r] that
    satisfies the lambda function check, if there
    is no such value the max/min possible value
    for that type will be returned.

  @Time:

    $O(\log{l-r+1})$
>8*/

template <typename T>
T maxCheck(T l, T r, function<bool(T)> check) {
  T best = numeric_limits<T>::min();
  while (l <= r) {
    T m = midpoint(l, r);
    if (check(m))
      chmax(best, m), l = m + 1;
    else
      r = m - 1;
  }
  return best;
}

template <typename T>
T minCheck(T l, T r, function<bool(T)> check) {
  T best = numeric_limits<T>::max();
  while (l <= r) {
    T m = midpoint(l, r);
    if (check(m))
      chmin(best, m), r = m - 1;
    else
      l = m + 1;
  }
  return best;
}
