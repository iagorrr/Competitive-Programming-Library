#include <bits/stdc++.h>

#include <queue>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define endl '\n'
#define fastio                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
// #define int long long
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
template <typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
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

bool check(const vector<set<int>> &G) {
  int N = len(G);
  vi degreeIn(N);

  for (auto adj : G)
    for (auto u : adj) degreeIn[u]++;

  dbg(degreeIn);

  set<pii> st;
  for (int i = 0; i < N; i++) {
    st.emplace(degreeIn[i], i);
  }

  while (len(st)) {
    auto [dgInU, u] = *st.begin();
    dbg(u);
    st.erase(*st.begin());

    if (dgInU != 0) return false;

    for (auto v : G[u]) {
      st.erase({degreeIn[v], v});
      degreeIn[v]--;
      st.insert({degreeIn[v], v});
    }
  }

  return true;
}

auto run() {
  int N, K;
  cin >> N >> K;

  vector<set<int>> G(N);
  vi degreeIn(N);

  for (int i = 0; i < K; i++) {
    int prev;
    for (int j = 0, cur; j < N; j++) {
      cin >> cur;
      cur--;
      if (j > 1) G[prev].emplace(cur);
      prev = cur;
    }
  }

  return check(G);
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  cin >> T;

  for (int t = 1; t <= T; t++) {
    dbg(t);
    cout << (run() ? "YES" : "NO") << '\n';
  }
}

// AC, graphs, topo sorting, cycles
