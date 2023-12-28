#include <bits/stdc++.h>
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

struct Lnode {
  ll v;
  bool assign;
  Lnode() : v(), assign() {}  // Neutral element
  Lnode(ll _v, bool a = 0) : v(_v), assign(a){};
};
using Qnode = ll;
using Unode = Lnode;

struct LSegTree {
  int n, ql, qr;
  vector<Qnode> st;
  vector<Lnode> lz;

  // How to merge two adjascents queries nodes
  Qnode merge(Qnode lv, Qnode rv, int nl, int nr) {
    return lv + rv;
  }

  // Apply lazy to a node and propague to it's
  // childs
  void prop(int i, int l, int r) {
    if (lz[i].assign) {
      st[i] = lz[i].v * (r - l + 1);
      if (l != r) lz[tol(i)] = lz[tor(i)] = lz[i];
    } else {
      st[i] += lz[i].v * (r - l + 1);
      if (l != r)
        lz[tol(i)].v += lz[i].v, lz[tor(i)].v += lz[i].v;
    }
    lz[i] = Lnode();
  }
  // Update Lnode with a Unode, as it is applied after a
  // propagation it's sure that is a neutral element already
  void applyV(int i, Unode v) {
    if (v.assign) {
      lz[i] = v;
    } else {
      lz[i].v += v.v;
    }
  }

  LSegTree() {}
  LSegTree(int _n) : n(_n), st(_n << 2), lz(_n << 2) {}
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
// vector<string> dir({"LU", "U", "RU", "R", "RD", "D",
// "LD", "L"}); int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}; int
// dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<string> dir({"U", "R", "D", "L"});
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const ll oo = 1e18;
int T(1);
const int MAXN(1'000'000);

auto solve() {}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif
  int N, Q;
  cin >> N >> Q;

  LSegTree st(N);
  vll xs(N);
  for (auto &xi : xs) cin >> xi;
  st.build(xs);

  while (Q--) {
    int o;
    cin >> o;
    if (o == 1) {
      ll a, b, x;
      cin >> a >> b >> x;
      a--, b--;
      st.upd(a, b, Unode(x));
    } else if (o == 2) {
      ll a, b, x;
      cin >> a >> b >> x;
      a--, b--;
      st.upd(a, b, Unode(x, true));
    } else {
      int a, b;
      cin >> a >> b;
      a--, b--;
      cout << st.qry(a, b) << '\n';
    }
  }
}

/*
 * AC
 * Segtree
 * Range Queries
 * Range update
 * https://cses.fi/problemset/task/1735/
 * */
