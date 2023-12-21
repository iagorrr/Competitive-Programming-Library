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
int N, M;
vi2d G(MAXN);
int timer;
int tin[MAXN], low[MAXN];
set<int> cpoints;

int dfs(int u, int p = -1) {
  int cnt = 0;
  low[u] = tin[u] = timer++;
  for (auto v : G[u]) {
    if (not tin[v]) {
      cnt++;
      dfs(v, u);

      if (low[v] >= tin[u]) cpoints.insert(u);
      low[u] = min(low[u], low[v]);
    } else if (v != p)
      low[u] = min(low[u], tin[v]);
  }

  return cnt;
}
void getCutPoints() {
  memset(low, 0, sizeof(low));
  memset(tin, 0, sizeof(tin));
  cpoints.clear();

  timer = 1;
  for (int i = 0; i < N; i++) {
    if (tin[i]) continue;
    int cnt = dfs(i);
    if (cnt == 1) cpoints.erase(i);
  }
}

auto solve() {
  cin >> N >> M;

  while (M--) {
    int a, b;
    cin >> a >> b;
    a--, b--;

    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }

  getCutPoints();

  cout << len(cpoints) << endl;
  for (auto i : cpoints) cout << i + 1 << ' ';
  cout << endl;
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

// AC, graphs,  articulation points
