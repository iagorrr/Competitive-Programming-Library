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

vector<string> dir({"LU", "U", "RU", "R", "RD", "D", "LD", "L"});
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
const ll oo = 1e18;

template <typename T = ll>
struct SegTree {
  int n;
  T nu, nq;
  vector<T> st;
  SegTree(const vector<T> &v)
    : n(len(v)), nu(LLONG_MAX), nq(LLONG_MAX), st(n * 4 + 1, nu) {
    for (int i = 0; i < n; ++i) update(i, v[i]);
  }

  SegTree(int _n) : n(_n), nu(LLONG_MAX), nq(LLONG_MAX), st(n * 4 + 1, nu) {
    for (int i = 0; i < n; ++i) update(i, LLONG_MAX);
  }
  void update(int p, T v) { update(1, 0, n - 1, p, v); }
  T query(int l, int r) { return query(1, 0, n - 1, l, r); }

  void update(int node, int nl, int nr, int p, T v) {
    if (p < nl or p > nr) return;

    if (nl == nr) {
      st[node] = v;
      return;
    }

    update(left(node), nl, mid(nl, nr), p, v);
    update(right(node), mid(nl, nr) + 1, nr, p, v);

    st[node] = st[left(node)] & st[right(node)];
  }

  T query(int node, int nl, int nr, int ql, int qr) {
    if (ql <= nl and qr >= nr) return st[node];
    if (nl > qr or nr < ql) return nq;
    if (nl == nr) return st[node];

    return query(left(node), nl, mid(nl, nr), ql, qr) &
           query(right(node), mid(nl, nr) + 1, nr, ql, qr);
  }

  int left(int p) { return p << 1; }
  int right(int p) { return (p << 1) + 1; }
  int mid(int l, int r) { return (r - l) / 2 + l; }
};
auto solve() {
  ll n;
  cin >> n;

  SegTree<ll> st((int)n);
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    st.update(i, x);
  }

  ll q;
  cin >> q;
  while (q--) {
    ll l, k;
    cin >> l >> k;
    l--;
    ll ans = -1;
    ll l2 = l, r2 = n - 1;
    while (l2 <= r2) {
      ll mid2 = (l2 + r2) / 2;
      if (st.query(l, mid2) >= k) {
        ans = max(ans, mid2);
        l2 = mid2 + 1;
      } else {
        r2 = mid2 - 1;
      }
    }
    cout << (ans == -1 ? -1 : ans + 1) << ' ';
  }
  cout << endl;
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  cin >> t;
  while (t--) solve();
}

// AC, segtree, binary search, bitmasks
