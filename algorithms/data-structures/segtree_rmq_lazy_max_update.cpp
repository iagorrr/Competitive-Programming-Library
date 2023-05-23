#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
struct SegmentTree {
  int N;
  vll ns, lazy;
  SegmentTree(const vll &xs) : N(xs.size()), ns(4 * N, 0), lazy(4 * N, 0) {
    for (size_t i = 0; i < xs.size(); ++i) {
      update(i, i, xs[i]);
    }
  }
  void update(int a, int b, ll value) { update(1, 0, N - 1, a, b, value); }
  void update(int node, int L, int R, int a, int b, ll value) {
    if (lazy[node]) {
      ns[node] = max(ns[node], lazy[node]);
      if (L < R) {
        lazy[2 * node] = max(lazy[2 * node], lazy[node]);
        lazy[2 * node + 1] = max(lazy[2 * node + 1], lazy[node]);
      }
      lazy[node] = 0;
    }
    if (a > R or b < L)
      return;
    if (a <= L and R <= b) {
      ns[node] = max(ns[node], value);
      if (L < R) {
        lazy[2 * node] = max(value, lazy[2 * node]);
        lazy[2 * node + 1] = max(value, lazy[2 * node + 1]);
      }
      return;
    }
    update(2 * node, L, (L + R) / 2, a, b, value);
    update(2 * node + 1, (L + R) / 2 +1, R, a, b, value);
    ns[node] = max(ns[node * 2], ns[node * 2 + 1]);
  }

  ll RMQ(int a, int b) { return RMQ(1, 0, N - 1, a, b); }
  ll RMQ(int node, int L, int R, int a, int b) {
    if (lazy[node]) {
      ns[node] = max(ns[node], lazy[node]);
      if (L < R) {
        lazy[node * 2] = max(lazy[node * 2], lazy[node]);
        lazy[node * 2 + 1] = max(lazy[node * 2 + 1], lazy[node]);
      }
      lazy[node] = 0;
    }

    if (a > R or b < L)
      return 0;
    if (a <= L and R <= b)
      return ns[node];
    ll x = RMQ(2 * node, L, (L + R) / 2, a, b);
    ll y = RMQ(2 * node + 1, (L + R) / 2 + 1, R, a, b);
    return max(x, y);
  }
};
