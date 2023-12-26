#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll oo = 1'000'000'000'000;

struct Node {
  ll value;

  Node() : value(oo) {}
  Node(ll _v) : value(_v){};
};

Node combine(const Node &vl, const Node &vr, int nl, int nr,
             int ql, int qr) {
  Node m;
  m.value = min(vl.value, vr.value);
  return m;
}

struct SegTree {
  int n;
  vector<Node> st;
  SegTree(int n) : n(n), st(n << 2) {}

  void assign(int p, const Node &v) {
    assign(1, 0, n - 1, p, v);
  }
  void assign(int node, int l, int r, int p,
              const Node &v) {
    if (l == r) {
      st[node] = v;
      return;
    }

    int m = midpoint(l, r);
    if (p <= m)
      assign(node << 1, l, m, p, v);
    else
      assign(node << 1 | 1, m + 1, r, p, v);

    st[node] =
      combine(st[node << 1], st[node << 1 | 1], l, r, l, r);
  }

  inline Node query(int l, int r) {
    return query(1, 0, n - 1, l, r);
  }

  inline Node query(int node, int nl, int nr, int l,
                    int r) const {
    if (r < nl or nr < l) return Node();
    if (l <= nl and nr <= r) return st[node];

    int m = midpoint(nl, nr);
    auto a = query(node << 1, nl, m, l, r);
    auto b = query(node << 1 | 1, m + 1, nr, l, r);

    return combine(a, b, nl, nr, l, r);
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
