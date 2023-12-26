#include <bits/stdc++.h>
using namespace std;

const int MAXN(2'00'000);
int N;
int ST[MAXN << 1], XS[MAXN];

void assign(int p, int x) {
  for (ST[p += N] = x; p >>= 1;)
    ST[p] = ST[p << 1] + ST[p << 1 | 1];
}

int query(int l, int r) {
  int ans = 0;
  for (l += N, r += N + 1; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ans += ST[l++];
    if (r & 1) ans += ST[--r];
  }
  return ans;
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    assign(i, 1);
    cin >> XS[i];
  }

  for (int i = 0; i < N; i++) {
    int p;
    cin >> p;

    int l = 0, r = N - 1;
    int ans = N;

    while (l <= r) {
      int mid = midpoint(l, r);
      int sum = query(0, mid);

      if (sum >= p) {
        ans = min(ans, mid);
        r = mid - 1;
      } else
        l = mid + 1;
    }

    cout << XS[ans] << " \n"[i == N - 1];
    assign(ans, 0);
  }
}


/*
 * AC
 * Segtree
 * Range sum query
 * Binary Search
 * https://cses.fi/problemset/task/1749/
 * */
