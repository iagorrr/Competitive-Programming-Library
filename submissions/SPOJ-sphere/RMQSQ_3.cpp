#include <bits/stdc++.h>
using namespace std;
#ifdef debug
#include "debug.cpp"
#else
#define dbg(...) 666
#endif
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(__x) (ll) __x.size()
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using vi2d = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vc = vector<char>;
#define all(a) a.begin(), a.end()
#define snd second
#define fst first
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)

const ll inf = 1e18;

template <typename t = ll>
struct segtree {
  int n;
  t nu;
  t nq;
  vector<t> st, lazy;
  segtree(const vector<t> &xs)
    : n(len(xs)),
      nu(0),
      nq(numeric_limits<t>::max()),
      st(4 * n, nu),
      lazy(4 * n, nu) {
    for (int i = 0; i < len(xs); ++i) update(i, i, xs[i]);
  }

  segtree(int n) : n(n), st(4 * n, nu), lazy(4 * n, nu) {}

  void update(int l, int r, ll value) { update(1, 0, n - 1, l, r, value); }

  t query(int l, int r) { return query(1, 0, n - 1, l, r); }

  void update(int node, int nl, int nr, int ql, int qr, ll v) {
    propagation(node, nl, nr);

    if (ql > nr or qr < nl) return;

    if (ql <= nl and nr <= qr) {
      st[node] += (nr - nl + 1) * v;

      if (nl < nr) {
        lazy[left(node)] += v;
        lazy[right(node)] += v;
      }

      return;
    }

    update(left(node), nl, mid(nl, nr), ql, qr, v);
    update(right(node), mid(nl, nr) + 1, nr, ql, qr, v);

    st[node] = min(st[left(node)], st[right(node)]);
  }

  t query(int node, int nl, int nr, int ql, int qr) {
    propagation(node, nl, nr);

    if (ql > nr or qr < nl) return nq;

    if (ql <= nl and nr <= qr) return st[node];

    t x = query(left(node), nl, mid(nl, nr), ql, qr);
    t y = query(right(node), mid(nl, nr) + 1, nr, ql, qr);

    return min(x, y);
  }

  void propagation(int node, int nl, int nr) {
    if (lazy[node]) {
      st[node] += lazy[node];

      if (nl < nr) {
        lazy[left(node)] += lazy[node];
        lazy[right(node)] += lazy[node];
      }

      lazy[node] = nu;
    }
  }

  int left(int p) { return p << 1; }
  int right(int p) { return (p << 1) + 1; }
  int mid(int l, int r) { return (r - l) / 2 + l; }
};

void run() {
  int n;
  cin >> n;
  vi a(n);
  for (auto &x : a) cin >> x;
  segtree<int> st(a);
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << st.query(l, r) << endl;
  }
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, segment tree, range sum update, range min query
