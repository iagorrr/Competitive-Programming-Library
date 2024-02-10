#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...) 42
#endif
#define endl '\n'
#define fastio                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
#define int long long
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
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define rep(i, begin, end)                              \
  for (__typeof(begin) i = (begin) - ((begin) > (end)); \
       i != (end) - ((begin) > (end));                  \
       i += 1 - 2 * ((begin) > (end)))

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

  /*---------------------------------------------------------------------*/

  Qnode merge(Qnode lv, Qnode rv, int nl, int nr) {
    return lv + rv;
  }

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

  void applyV(int i, Unode v) {
    if (v.assign) {
      lz[i] = v;
    } else {
      lz[i].v += v.v;
    }
  }
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
  int n, m;
  cin >> n >> m;

  vll tmp(n);
  for (auto &ai : tmp) cin >> ai;

  LSegTree seg(n);
  for (int i = 0; i < n; i++) {
    seg.upd(i, i, tmp[i]);
  }

  vll bs(m);
  for (auto &bi : bs) cin >> bi;

  for (int i = 0; i < m; i++) {
    int bi = bs[i];
    ll c = seg.qry(bi, bi);
    seg.upd(bi, bi, -c);

    // se how many complete cicles
    ll complete = c / n;
    seg.upd(0, n - 1, complete);

    c = c % n;

    if (c) {
      if (bi == n - 1) {
        seg.upd(0, c-1, 1);
      } else {
        seg.upd(bi + 1, min(n - 1, bi + 1 + c - 1), 1);
        int updated =
          min(n - 1, bi + 1 + c - 1) - (bi + 1) + 1;
        c -= updated;
        if (c) seg.upd(0, c - 1, 1);
      }
    }

    // increase the rest !

    // while (c) {
    //   bi = (bi + 1) % n;
    //   seg.upd(bi, bi, 1);
    //   c--;
    // }
  }

  for (int i = 0; i < n; i++) {
    cout << seg.qry(i, i) << " \n"[i == n - 1];
  }
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

// AC, data structures
