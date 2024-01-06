#include <bits/stdc++.h>

#include <queue>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...) 42
#endif
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(__x) (int)__x.size()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using vi2d = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vc = vector<char>;
#define all(a) a.begin(), a.end()
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)
int lg2(ll x) {
  return __builtin_clzll(1) - __builtin_clzll(x);
}

// vector<string> dir({"LU", "U", "RU", "R", "RD", "D",
// "LD", "L"}); int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}; int
// dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<string> dir({"U", "R", "D", "L"});
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const ll oo = 1e18;
int T(1);
const int MAXN(1'000'000);

using Lnode = ll;
struct Qnode {
  ll v;
  Qnode() : v(oo) {}
  Qnode(ll _v) : v(_v) {}
};

using Unode = ll;

struct LSegTree {
  int n, ql, qr;
  vector<Qnode> st;
  vector<Lnode> lz;

  /*---------------------------------------------------------------------*/
  Qnode merge(Qnode lv, Qnode rv, int nl, int nr) {
    return Qnode(min(lv.v, rv.v));
  }

  void prop(int i, int l, int r) {
    st[i].v += lz[i];
    if (l != r) lz[tol(i)] += lz[i], lz[tor(i)] += lz[i];
    lz[i] = 0;
  }

  void applyV(int i, Unode v) { lz[i] += v; }
  /*---------------------------------------------------------------------*/
  LSegTree() {}
  LSegTree(int _n) : n(_n), st(_n << 2), lz(_n << 2) {}
  bool disjoint(int l, int r) { return qr < l or r < ql; }
  bool contains(int l, int r) {
    return ql <= l and r <= qr;
  }
  int tol(int i) { return i << 1; }
  int tor(int i) { return i << 1 | 1; }
  void build(vector<Qnode> &v) { build(v, 1, 0, n - 1); }
  void build(vector<Qnode> &v, int i, int l, int r) {
    if (l == r) {
      st[i] = v[l];
      return;
    }
    int m = midpoint(l, r);
    build(v, tol(i), l, m);
    build(v, tor(i), m + 1, r);
    st[i] = merge(st[tol(i)], st[tor(i)], l, r);
  }
  void upd(int l, int r, Unode v) {
    ql = l, qr = r;
    upd(1, 0, n - 1, v);
  }
  void upd(int i, int l, int r, Unode v) {
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
  Qnode qry(int l, int r) {
    ql = l, qr = r;
    return qry(1, 0, n - 1);
  }
  Qnode qry(int i, int l, int r) {
    prop(i, l, r);
    if (disjoint(l, r)) return Qnode();
    if (contains(l, r)) return st[i];
    int m = midpoint(l, r);
    return merge(qry(tol(i), l, m), qry(tor(i), m + 1, r),
                 l, r);
  }
};
auto run() {
  int n;
  cin >> n;
  vll xs(n);
  for (int i = 0; i < n; i++) {
    cin >> xs[i];
  }

  priority_queue<pair<ll, ll>> pq;
  int ans = 0;

  vector<Qnode> ys(n, 0);
  for (int i = 0; i < n; i++) {
    if (i) ys[i].v += ys[i - 1].v;

    if (xs[i] < 0) {
      pq.emplace(xs[i], i);
    } else {
      ans++;
      ys[i].v += xs[i];
    }
  }

  LSegTree st(n);
  st.build(ys);

  while (not pq.empty()) {
    auto [v, p] = pq.top();
    pq.pop();

    if (st.qry(p, n - 1).v < abs(v)) continue;

    ans++;
    st.upd(p, n - 1, v);
  }

  cout << ans << '\n';
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  // cin >> T;

  for (int i = 1; i <= T; i++) {
    run();
  }
}

/*
 * AC
 * Range Query
 * Greedy
 * https://codeforces.com/problemset/problem/1526/C1
 * */
