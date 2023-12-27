#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

// Neutral elements
const ll eQuery = -1e18;
const ll eLazy = 0ll;

template <class T1 = ll, class T2 = ll>
struct LSegTree {
  int n, ql, qr;
  vector<T1> st;
  vector<T2> lz;

  // How to merge two adjascents queries nodes
  T1 merge(T1 lv, T1 rv, int nl, int nr) {
    return max(lv, rv);
  }
  // Apply lazy to a node and propague to it's
  // childs
  void prop(int i, int l, int r) {
    st[i] += lz[i];
    if (l != r) lz[i * 2] += lz[i], lz[i * 2 + 1] += lz[i];
    lz[i] = 0;
  }
  // Update lazy with a value
  void applyV(int i, T1 v) { lz[i] += v; }

  LSegTree() {}
  LSegTree(int _n)
    : n(_n), st(n << 2, eQuery), lz(n << 2, eLazy) {}
  bool disjoint(int l, int r) { return qr < l or r < ql; }
  bool contains(int l, int r) {
    return ql <= l and r <= qr;
  }
  int tol(int i) { return i << 1; }
  int tor(int i) { return i << 1 | 1; }
  void build(vll &v) { build(v, 1, 0, n - 1); }
  void build(vll &v, int i, int l, int r) {
    if (l == r) {
      st[i] = v[l];
      return;
    }
    int m = midpoint(l, r);
    build(v, tol(i), l, m);
    build(v, tor(i), m + 1, r);
    st[i] = merge(st[tol(i)], st[tor(i)], l, r);
  }
  void upd(int l, int r, T1 v) {
    ql = l, qr = r;
    upd(1, 0, n - 1, v);
  }
  void upd(int i, int l, int r, T1 v) {
    prop(i, l, r);
    if (disjoint(l, r)) return;
    if (contains(l, r)) {
      applyV(i, v);
      prop(i, l, r);
      return;
    }
    int m = midpoint(l, r);
    upd(tol(i), l, m, v);
    upd(tor(i), m + 1, r, v);
    st[i] = merge(st[tol(i)], st[tor(i)], l, r);
  }
  T1 qry(int l, int r) {
    ql = l, qr = r;
    return qry(1, 0, n - 1);
  }
  T1 qry(int i, int l, int r) {
    prop(i, l, r);
    if (disjoint(l, r)) return eQuery;
    if (contains(l, r)) return st[i];
    int m = midpoint(l, r);
    return merge(qry(tol(i), l, m), qry(tor(i), m + 1, r),
                 l, r);
  }
};

int main() {
  int n, q;
  vll xs, ps;
  cin >> n >> q;
  xs = ps = vll(n);
  for (auto &xi : xs) cin >> xi;

  ps[0] = xs[0];
  for (int i = 1; i < n; i++) ps[i] = ps[i - 1] + xs[i];

  LSegTree st(n);
  st.build(ps);

  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int i;
      ll x;
      cin >> i >> x;
      i--;
      st.upd(i, n - 1, x - xs[i]);
      xs[i] = x;
    } else {
      int a, b;
      cin >> a >> b;
      a--, b--;
      ll pre = a ? st.qry(a - 1, a - 1) : 0;
      cout << max(st.qry(a - 1, b) - pre, 0ll) << '\n';
    }
  }
}

/*
 * AC
 * https://cses.fi/problemset/task/2166/
 * Range queries
 * Segtree
 * Lazy Propagation
 * */
