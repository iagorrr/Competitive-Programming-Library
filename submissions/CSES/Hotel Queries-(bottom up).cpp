#include <bits/stdc++.h>

using namespace std;
const int MAXN(2'00'000), oo(1'000'000'001);
int N, Q;

struct Node {
  int value;
  Node() : value(-oo){};  // Neutral element
  Node(int v) : value(v){};
};

Node combine(Node &l, Node &r) {
  Node m;
  m.value = max(l.value, r.value);
  return m;
}
struct SegTree {
  int n;
  vector<Node> st;
  SegTree(int n) : n(n), st(n << 1) {}

  void assign(int p, const Node &k) {
    for (st[p += n] = k; p >>= 1;)
      st[p] = combine(st[p << 1], st[p << 1 | 1]);
  }

  Node query(int l, int r) {
    Node ansl, ansr;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) ansl = combine(ansl, st[l++]);
      if (r & 1) ansr = combine(st[--r], ansr);
    }
    return combine(ansl, ansr);
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> Q;
  SegTree st(N);
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    st.assign(i, x);
  }

  while (Q--) {
    int x;
    cin >> x;

    int ans = N;
    int l = 0, r = N - 1;
    while (l <= r) {
      int mid = midpoint(l, r);
      int rmq = st.query(0, mid).value;
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
      st.assign(ans, st.query(ans, ans).value - x);
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
