#include <bits/stdc++.h>
using namespace std;
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
#define snd second
#define fst first
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)

const ll oo = 1e18;

template <typename T = ll>
struct SegTree {
  int N;
  T nu;
  T nq;
  vector<T> st, lazy;
  SegTree(const vector<T> &xs)
    : N(len(xs)), nu(0), nq(0), st(4 * N, nu), lazy(4 * N, nu) {
    for (int i = 0; i < len(xs); ++i) update(i, i, xs[i]);
  }

  SegTree(int n) : N(n), nu(0), nq(0), st(4 * N, nu), lazy(4 * N, nu) {
    for (int i = 0; i < n; i++) update(i, i, 0);
  }

  void update(int l, int r, ll value) { update(1, 0, N - 1, l, r, value); }

  T query(int l, int r) { return query(1, 0, N - 1, l, r); }

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

    st[node] = st[left(node)] + st[right(node)];
  }

  T query(int node, int nl, int nr, int ql, int qr) {
    propagation(node, nl, nr);

    if (ql > nr or qr < nl) return nq;

    if (ql <= nl and nr <= qr) return st[node];

    T x = query(left(node), nl, mid(nl, nr), ql, qr);
    T y = query(right(node), mid(nl, nr) + 1, nr, ql, qr);

    return x + y;
  }

  void propagation(int node, int nl, int nr) {
    if (lazy[node]) {
      st[node] += (nr - nl + 1) * lazy[node];

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

void dfs(int u, int p, int &m, vi2d &g, vi &start, vi &end) {
  start[u] = m;
  for (auto v : g[u])
    if (v != p) {
      m++;
      dfs(v, u, m, g, start, end);
    }
  end[u] = m;
}

void run() {
  int n, q;
  cin >> n >> q;

  vi2d g(n);
  vll v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].eb(b);
    g[b].eb(a);
  }

  vi start(n);
  vi end(n);
  int m = 0;
  dfs(0, -1, m, g, start, end);

  SegTree<ll> st(n);
  for (int i = 0; i < n; i++) {
    st.update(start[i], start[i], v[i]);
  }
  while (q--) {
    int o;
    cin >> o;

    int a;
    cin >> a;
    a--;
    if (o == 2) {
      cout << st.query(start[a], end[a]) << endl;
    } else {
      ll x;
      cin >> x;
      st.update(start[a], start[a], x - st.query(start[a], start[a]));
    }
  }
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, trees, subtree queries
