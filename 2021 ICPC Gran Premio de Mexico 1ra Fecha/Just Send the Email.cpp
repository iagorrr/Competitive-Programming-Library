#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(x) (int)x.size()
#define all(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;

void dfs(const vector<vector<int>> &g, int u, vector<int> &dist) {
  if (g[u].empty()) {
    dist[u] = 0;
    return;
  }
  int mn = INT_MAX;
  for (auto x : g[u]) {
    dfs(g, x, dist);
    mn = min(mn, dist[x] + 1);
  }
  dist[u] = mn;
}

void dfs2(const vector<vector<int>> &g, int u, vector<int> &exp,
          const vector<int> &dist) {
  if (g[u].empty()) {
    exp[u] = 1;
    return;
  }

  exp[u] = min(exp[u], dist[u] + 1);
  for (auto x : g[u]) {
    exp[x] = exp[u] + 1;
    dfs2(g, x, exp, dist);
  }
}

const auto mod = 998244353;
ll fpow(ll x, ll p) {
  if (p == 0) return 1;
  ll ans = fpow(x, p >> 1);
  ans = (ans * ans) % mod;
  if (p & 1) ans = (ans * x) % mod;
  return ans;
}

void run() {
  int n;
  cin >> n;

  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    --x;
    g[x].push_back(i);
  }

  vector<int> dist(n);
  dfs(g, 0, dist);

  vector<int> exp(n, INT_MAX);
  dfs2(g, 0, exp, dist);

  ll sum = accumulate(all(exp), 0ll);
  cout << sum * fpow(n, mod - 2) % mod << '\n';
}

int32_t main() {
  fastio;
  int t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, graphs, trees, expected value
