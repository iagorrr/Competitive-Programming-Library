#include <bits/stdc++.h>

using namespace std;
const int MAXN(2'00'000), oo(1'000'000'001);
int N, Q;
int ST[MAXN << 1];

void assign(int p, int v) {
  for (ST[p += N] = v; p >>= 1;)
    ST[p] = max(ST[p << 1], ST[p << 1 | 1]);
}

int query(int l, int r) {
  int ans = -oo;
  for (l += N, r += N + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ans = max(ans, ST[l++]);
    if (r & 1) ans = max(ans, ST[--r]);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> Q;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    assign(i, x);
  }

  while (Q--) {
    int x;
    cin >> x;

    int ans = N;
    int l = 0, r = N - 1;
    while (l <= r) {
      int mid = midpoint(l, r);
      int rmq = query(0, mid);
      if (rmq >= x) {
        ans = min(ans, mid);
        r = mid - 1;

      } else {
        l = mid + 1;
      }
    }

    if (ans == N) {
      cout << 0 << ' ';
    } else {
      cout << ans + 1 << ' ';
      assign(ans, query(ans, ans) - x);
    }
  }

  cout << '\n';
}

/*
 * AC
 * Segtree
 * Range Min Query
 * https://cses.fi/problemset/task/1143/
 * */
