// iagorrr ;) implementaion by edsomjr
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree {
  int N;
  std::vector<ll> ns, lazy;

  SegTree(const std::vector<ll> &xs)
      : N(xs.size()), ns(4 * N, 0), lazy(4 * N, 0) {
    for (size_t i = 0; i < xs.size(); ++i)
      update(i, i, xs[i]);
  }

  void update(int a, int b, ll value) { update(1, 0, N - 1, a, b, value); }

  void update(int node, int L, int R, int a, int b, ll value) {
    // Lazy propagation
    if (lazy[node]) {
      ns[node] += (R - L + 1) * lazy[node];

      if (L < R) // Se o nó não é uma folha, propaga
      {
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
      }

      lazy[node] = 0;
    }

    // [a, b] ∩ [L, R] = {∅}
    if (a > R or b < L)
      return;

    // [L, R] ⊂ [a, b] está contido; é subconjunto de
    if (a <= L and R <= b) {
      ns[node] += (R - L + 1) * value;

      if (L < R) {
        lazy[2 * node] += value;
        lazy[2 * node + 1] += value;
      }

      return;
    }

    update(2 * node, L, (L + R) / 2, a, b, value);
    update(2 * node + 1, (L + R) / 2 + 1, R, a, b, value);

    ns[node] = ns[2 * node] + ns[2 * node + 1];
  }

  ll RSQ(int a, int b) { return RSQ(1, 0, N - 1, a, b); }

  ll RSQ(int node, int L, int R, int a, int b) {
    if (lazy[node]) {
      ns[node] += (R - L + 1) * lazy[node];

      if (L < R) {
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
      }

      lazy[node] = 0;
    }

    if (a > R or b < L)
      return 0;

    if (a <= L and R <= b)
      return ns[node];

    ll x = RSQ(2 * node, L, (L + R) / 2, a, b);
    ll y = RSQ(2 * node + 1, (L + R) / 2 + 1, R, a, b);

    return x + y;
  }

  void debug() {
    for (int i = 0; i <= N; ++i) {
      cout << "(" << i << ',' << RSQ(i, i) << ") ";
    }
    cout << '\n';
  }
};

signed main() {}
