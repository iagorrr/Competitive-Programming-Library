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
const int MAXN(3'000'000);

struct Node {
  ll value;
  Node() : value(oo){};  // Neutral element
  Node(ll v) : value(v){};
};

Node combine(Node &l, Node &r) {
  Node m;
  m.value = min(l.value, r.value);
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

const ll MOD(998244353);
int N;
ll XS[MAXN];
SegTree st(MAXN);
map<ll, int> POS;

ll solve(int l, int r, int mask) {
  if (l == r) return 1;
  if (l > r) return 0;  // invalid susequence
  ll m = POS[st.query(l, r).value];
  ll lv = solve(l, m - 1, mask | 1);
  ll rv = solve(m + 1, r, mask | 2);
  ll ret = ((lv + 1) * (rv + 1)) % MOD;
  if (mask & 1) ret = (ret + lv) % MOD;
  if (mask & 2) ret = (ret + rv) % MOD;
  return ret;
}

auto run() {
  POS.clear();
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> XS[i];
    POS[XS[i]] = i;
    st.assign(i, Node(XS[i]));
  }
  auto ans = solve(0, N - 1, 0);
  cout << ans << '\n';
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  cin >> T;

  for (int i = 1; i <= T; i++) {
    run();
  }
}

/*
 * Divide and conquer
 * Data strucutres
 * rmq
 * */
