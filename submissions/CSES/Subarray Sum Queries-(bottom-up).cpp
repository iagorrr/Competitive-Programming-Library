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
const int MAXN(1'000'000);

struct Node {
  ll tot, suf, pref, best;
  Node()
    : tot(-oo),
      suf(-oo),
      pref(-oo),
      best(-oo) {}  // Neutral element
  Node(ll x) {      // for assign
    tot = x, suf = x, pref = x, best = max(0ll, x);
  }
};

Node combine(Node &nl, Node &nr) {
  if (nl.tot == -oo) return nr;
  if (nr.tot == -oo) return nl;
  Node m;
  m.tot = nl.tot + nr.tot;
  m.pref = max({nl.pref, nl.tot + nr.pref});
  m.suf = max({nr.suf, nr.tot + nl.suf});
  m.best = max({nl.best, nr.best, nl.suf + nr.pref});
  return m;
}

struct SegTree {
  int n;
  vector<Node> st;
  SegTree(int _n) : n(_n), st(n << 1) {}

  void assign(int p, const Node &k) {
    for (st[p += n] = k; p >>= 1;)
      st[p] = combine(st[p << 1], st[p << 1 | 1]);
  }

  Node query(int l, int r) {
    Node ansl, ansr;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) ansl = combine(ansl, st[l++]);
      if (r & 1) ansr = combine(st[--r], ansr);
    }
    return combine(ansl, ansr);
  }
};
auto solve() {}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  int N, Q;
  cin >> N >> Q;
  SegTree st(N);

  for (int i = 0; i < N; i++) {
    ll x;
    cin >> x;
    st.assign(i, Node(x));
  }

  while (Q--) {
    ll x;
    int p;
    cin >> p >> x;
    p--;
    st.assign(p, x);
    auto ans = st.query(0, N - 1);
    // dbg(ans.pref, ans.suf, ans.tot);
    cout << ans.best << '\n';
  }
}

/*
 * AC
 * Segment tree
 * Max sub array sum
 * bottom up
 * point update
 * https://cses.fi/problemset/task/1190/
 * */
