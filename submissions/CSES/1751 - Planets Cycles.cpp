#include <bits/stdc++.h>
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

const ll OO = 1e18;
const int oo = 1e9;

int T(1);

vi G, vis, ans, inCycle, dists;

int flagCycle = -1;
int firstOfCycle;
void dfs(int u, int dist = 1) {
  dists[u] = dist;
  vis[u] = 1;

  int v = G[u];
  if (!vis[v]) {
    dfs(v, dist + 1);
    dbg(u, v, firstOfCycle, inCycle[v]);
    if (inCycle[v]) {
      if (flagCycle == 1) {
        inCycle[u] = 1;
        ans[u] = ans[v];
        flagCycle = u != firstOfCycle ? 1 : -1;
      } else
        ans[u] = ans[v] + 1;
    } else
      ans[u] = ans[v] + 1;

    vis[u] = 2;
  } else if (vis[v] == 1) {
    flagCycle = v != u;
    firstOfCycle = v;
    dbg("cycle found", u, v, firstOfCycle);
    inCycle[u] = 1;
    ans[u] = dists[u] - dists[v] + 1;
    vis[u] = 2;
  } else if (vis[v] == 2) {
    ans[u] = ans[v] + 1;
    vis[u] = 2;
  }
}
auto run() {
  int N;
  cin >> N;
  ans.resize(N), vis.resize(N), G.resize(N),
    inCycle.resize(N), dists.resize(N);

  for (auto &gi : G) cin >> gi, gi--;

  for (int i = 0; i < N; i++) {
    if (!vis[i]) dfs(i);
  }

  dbg(inCycle);
  for (int i = 0; i < N; i++) {
    cout << ans[i] << " \n"[i == N - 1];
  }
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  // cin >> T;

  for (int t = 1; t <= T; t++) {
    run();
  }
}

// AC, functional graphs
