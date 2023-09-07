#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(__x) (int)__x.size()
using ll = long long;
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
  int n;
  T nu, nq;
  vector<T> st;
  SegTree(const vector<T> &v) : n(len(v)), nu(0), nq(0), st(n * 4 + 1, nu) {
    for (int i = 0; i < n; ++i) update(i, v[i]);
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

    st[node] = st[left(node)] ^ st[right(node)];
  }

  T query(int node, int nl, int nr, int ql, int qr) {
    if (ql <= nl and qr >= nr) return st[node];
    if (nl > qr or nr < ql) return nq;
    if (nl == nr) return st[node];

    return query(left(node), nl, mid(nl, nr), ql, qr) ^
           query(right(node), mid(nl, nr) + 1, nr, ql, qr);
  }

  int left(int p) { return p << 1; }
  int right(int p) { return (p << 1) + 1; }
  int mid(int l, int r) { return (r - l) / 2 + l; }
};
void run() {
  ll n;
  cin >> n;
  vll xs(n);
  for (int i = 0; i < n; i++) {
    cin >> xs[i];
  }
  string s;
  cin >> s;

  ll xor0 = 0, xor1 = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1')
      xor1 ^= xs[i];
    else
      xor0 ^= xs[i];
  }

  ll q;
  cin >> q;
  SegTree<ll> st(xs);
  while (q--) {
    ll o;
    cin >> o;
    if (o == 1) {
      ll l, r;
      cin >> l >> r;
      xor1 ^= st.query(l - 1, r - 1);
      xor0 ^= st.query(l - 1, r - 1);
    } else {
      ll p;
      cin >> p;
      if (p)
        cout << xor1 << ' ';
      else
        cout << xor0 << ' ';
    }
  }
  cout << endl;
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  cin >> t;
  while (t--) run();
}

// AC, bitmask, data structure
