#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll oo = 1'000'000'000'000;

struct Node {
  ll value;
  Node() : value(oo){};  // Neutral element
  Node(ll v) : value(v){};
};

Node combine(Node &l, Node &r) {
  Node m;
  m.value = min(l.value, r.value);
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

int N, Q;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> Q;

  SegTree st(N);
  for (int i = 0; i < N; i++) {
    ll k;
    cin >> k;
    st.assign(i, Node(k));
  }

  while (Q--) {
    ll a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      st.assign(b - 1, Node(c));
    } else {
      cout << st.query(b - 1, c - 1).value << '\n';
    }
  }
}

/*
 * AC
 * Range Queries
 * Segment tree
 * Point update
 * https://cses.fi/problemset/task/1648/
 */
