const int MAXN(10000), MAXM(100000);
int N, M, clk, tin[MAXN], low[MAXN], isBridge[MAXM];
vector<pii> G[MAXN];

void dfs(int u, int p = -1) {
  tin[u] = low[u] = clk++;

  for (auto [v, i] : G[u]) {
    if (v == p) continue;
    if (tin[v]) {
      low[u] = min(low[u], tin[v]);
    } else {
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] > tin[u]) {
        isBridge[i] = 1;
      }
    }
  }
}

void findBridges() {
  fill(tin, tin + N, 0);
  fill(low, low + N, 0);
  fill(isBridge, isBridge + M, 0);
  clk = 1;
  for (int i = 0; i < N; i++) {
    if (!tin[i]) dfs(i);
  }
}
