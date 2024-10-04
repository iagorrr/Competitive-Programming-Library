/*8<
        @Title:
                Count inversions

        @Description:
                Count the number of inversions when transforming the vector $l$
                in the vector $r$, which is also equivalent to the mininum
                number of swaps required.

        @Usage:
                If no $r$ vector is provided it considers r as the sorted
                vector, if there is no such way to turn $l$ into $r$ using swaps
                then $-1$ is returned

        @Time:
                $O(N\log{N})$

        @Problems:
                https://codeforces.com/problemset/problem/1430/E
>8*/
#pragma once
#include "../Contest/template.cpp"

template <typename T>
ll countInversions(vector<T> l, vector<T> r = {}) {
  if (!len(r)) r = l, sort(all(r));
  int n = len(l);
  vi v(n), bit(n);
  vector<pair<T, int>> w;
  rep(i, 0, n) w.eb(r[i], i + 1);
  sort(all(w));
  rep(i, 0, n) {
    auto it = lower_bound(all(w), make_pair(l[i], 0));
    if (it == w.end() or it->first != l[i]) return -1;  // impossible
    v[i] = it->second;
    it->second = -1;
  }
  ll ans = 0;
  rrep(i, n - 1, 0 - 1) {
    for (int j = v[i] - 1; j; j -= j & -j) ans += bit[j];
    for (int j = v[i]; j < n; j += j & -j) bit[j]++;
  }
  return ans;
}
