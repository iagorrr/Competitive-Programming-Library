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

// vector<string> dir({"LU", "U", "RU", "R", "RD", "D",
// "LD", "L"}); int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}; int
// dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<string> dir({"U", "R", "D", "L"});
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const ll oo = 1e18;
int T(1);

const ll P = 31;
const ll MOD = 1'000'000'009;
const int MAXN(1'000'000);
vll pows(MAXN);

void precalcpows() {
  pows[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    pows[i] = (pows[i - 1] * P) % MOD;
  }
}
struct Segtree {
  int n;
  vll xs;
  Segtree(const string &_s)
    : n(len(_s)), xs(4 * n + 1, -1) {
    for (int i = 0; i < n; i++) {
      update(i, _s[i]);
    }
    // seg_build(1, 0, n - 1, _s);
  }

  void seg_build(int x, int l, int r, const string &s) {
    if (r < l) return;
    if (l == r) {
      xs[x] = (s[l] - 'a' + 1);
    } else {
      int mid = l + (r - l) / 2;
      seg_build(x + x, l, mid, s);
      seg_build(x + x + 1, mid + 1, r, s);
      xs[x] = merge(xs[x + x], xs[x + x + 1], mid - l + 1);
    }
  }

  void update(int p, char c) { update(1, 0, n - 1, p, c); }
  void update(int i, int l, int r, int p, char c) {
    if (p < l or p > r) return;
    if (l == r) {
      xs[i] = c - 'a' + 1;
      return;
    }

    int mid = midpoint(l, r);

    update(i + i, l, mid, p, c);
    update(i + i + 1ll, mid + 1, r, p, c);

    xs[i] = merge(xs[i + i], xs[i + i + 1],
                  midpoint(l, r) - l + 1);
  }

  ll merge(ll a, ll b, int sz) {
    if (a == -1) return b;
    if (b == -1) return a;

    return (a + b * pows[sz]) % MOD;
  }

  ll query(int l, int r) {
    return query(1, 0, n - 1, l, r);
  }

  ll query(int u, int lu, int ru, int l, int r) {
    if (lu > r or ru < l) return -1;
    if (l <= lu and ru <= r) return xs[u];

    int mid = midpoint(lu, ru);
    ll a = query(u +u, lu, mid, l, r);
    ll b = query(u +u+1, mid + 1, ru, l, r);

    return merge(a, b, midpoint(lu, ru) - max(l, lu) + 1);
  }
};

auto solve() {
  precalcpows();
  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;

  Segtree seg(S);
  reverse(all(S));
  Segtree rseg(S);

  while (Q--) {
    int o;
    cin >> o;
    switch (o) {
      case 1:
        char c;
        int p;
        cin >> p >> c;
        p--;
        seg.update(p, c);
        rseg.update(N - p - 1, c);
        break;
      case 2:
        int l, r;
        cin >> l >> r;
        l--, r--;
        ll a = seg.query(l, r);
        ll b = rseg.query(N - r - 1, N - l - 1);

        cout << (a == b ? "Yes" : "No") << endl;
        break;
    }
  }
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  // cin >> T;

  for (int i = 1; i <= T; i++) {
    solve();
  }
}

/*
 * AC
 * Segmentree
 * Strings
 * Hash
 * */
