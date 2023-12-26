#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD(1'000'000'009), P(31);
ll pows[1'000'000 + 1];
void computepows() {
  pows[0] = 1;
  for (int i = 1; i <= 1'000'000; i++) {
    pows[i] = (pows[i - 1] * P) % MOD;
  }
}

struct Node {
  ll hash;
  Node() : hash(-1){};  // Neutral element
  Node(ll v) : hash(v){};
};

inline Node combine(Node &vl, Node &vr, int nl, int nr,
                    int ql, int qr) {
  if (vl.hash == -1) return vr;
  if (vr.hash == -1) return vl;
  Node vm;

  int nm = midpoint(nl, nr);
  int lsize = min(nm, qr) - max(nl, ql) + 1;
  vm.hash =
    (vl.hash + ((vr.hash * pows[lsize]) % MOD)) % MOD;
  return vm;
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
int f(char c) { return c - 'a' + 1; }

int r(int k, int n) { return n - k - 1; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  computepows();

  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;

  SegTree st(n), rst(n);
  for (int i = 0; i < n; i++) {
    st.assign(i, Node(f(s[i])));
    rst.assign(i, Node(f(s[r(i, n)])));
  }

  while (q--) {
    int o;
    cin >> o;
    if (o == 1) {
      int k;
      char c;
      cin >> k >> c;
      k--;
      st.assign(k, Node(f(c)));
      rst.assign(r(k, n), Node(f(c)));
    } else {
      int a, b;
      cin >> a >> b;
      a--, b--;

      cout << (st.query(a, b).hash ==
                   rst.query(r(b, n), r(a, n)).hash
                 ? "Yes\n"
                 : "No\n");
    }
  }
}

/*
 * AC
 * Segtree
 * point update
 * Hash query
 * top down
 * https://atcoder.jp/contests/abc331/tasks
 * */
