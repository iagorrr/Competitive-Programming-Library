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
const int MAXN(200);

int N;
pii pts[MAXN + 1];
ll power[MAXN];

ll manha(int i, int j) {
  auto [a, b] = pts[i];
  auto [c, d] = pts[j];
  return abs(a - c) + abs(b - d);
}

bool vis[MAXN + 1];
int viscnt;
void dfs(int u, ll s) {
  viscnt++;
  vis[u] = 1;
  for (int i = 1; i <= N; i++) {
    if (vis[i]) continue;
    if (power[u] * s >= manha(u, i)) dfs(i, s);
  }
}

bool check(ll s) {
  for (int i = 1; i <= N; i++) {
    fill(vis, vis + N + 1, 0);
    viscnt = 0;
    dfs(i, s);
    if (viscnt == N) return 1;
  }
  return false;
}

auto run() {
  cin >> N;

  for (int i = 1; i <= N; i++) {
    cin >> pts[i].first >> pts[i].second >> power[i];
  }

  ll l = 0, r = 9'000'000'000;
  ll ans = r;
  while (l <= r) {
    auto m = midpoint(l, r);
    if (check(m)) {
      ans = min(ans, m);
      r = m - 1;
    } else
      l = m + 1;
  }

  cout << ans << '\n';
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

// AC, binary search, dfs/bfs
