#include <bits/stdc++.h>
using namespace std;

const int maxn(5'0'000);
int n, m;
vector<pair<int, int>> adj[maxn], extraAdj[maxn];

int tin[maxn], lastOut[maxn], timer = 1;
void setTimer(int u) {
  tin[u] = lastOut[u] = timer++;

  for (auto [v, _] : adj[u]) {
    if (!tin[v]) {
      setTimer(v);
      lastOut[u] = max(lastOut[v], lastOut[u]);
    }
  }
}

int ans[maxn];
set<pair<int, int>> lowLinks[maxn];
void dfs(int u, int p = -1) {
  for (auto [v, idx] : adj[u]) {
    if (v == p) continue;
    dfs(v, u);

    while (lowLinks[v].size()) {
      int v2 = lowLinks[v].begin()->second;
      if (tin[v2] < tin[v] or tin[v2] > lastOut[v]) break;
      lowLinks[v].erase(lowLinks[v].begin());
    }

    if (lowLinks[v].size()) {
      ans[idx] = lowLinks[v].begin()->first;
    } else {
      ans[idx] = -1;
    }

    if (lowLinks[v].size() > lowLinks[u].size()) {
      lowLinks[u].swap(lowLinks[v]);
    }

    for (auto [c, v] : lowLinks[v]) {
      lowLinks[u].emplace(c, v);
    }
  }

  for (auto [v, c] : extraAdj[u]) {
    if (tin[v] < tin[u] or tin[v] > lastOut[u]) {
      lowLinks[u].emplace(c, v);
    }
  }
}

int32_t main() {
  ifstream in("disrupt.in");
  ofstream out("disrupt.out");
  in >> n >> m;

  for (int i = 0, a, b; i < n - 1; i++) {
    in >> a >> b;
    a--, b--;
    adj[a].emplace_back(b, i);
    adj[b].emplace_back(a, i);
  }

  for (int i = 0, a, b, c; i < m; i++) {
    in >> a >> b >> c;
    a--, b--;
    extraAdj[a].emplace_back(b, c);
    extraAdj[b].emplace_back(a, c);
  }

  setTimer(0);
  dfs(0);

  for (int i = 0; i < n - 1; i++) {
    out << ans[i] << '\n';
  }
}

// AC, small to large, low link
