const int MAXN(1'000'000);
int tin[MAXN], low[MAXN], timer, N;
vi2d G(MAXN);
vector<pii> bridges;

void dfs(int u, int p = -1) {
  tin[u] = low[u] = timer++;

  for (auto v : G[u]) {
    if (v == p) continue;
    if (tin[v]) {
      low[u] = min(low[u], tin[v]);
    } else {
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] > tin[u]) {
        bridges.emplace_back(u, v);
      }
    }
  }
}
void findBridges() {
  timer = 1;
  bridges.clear();
  memset(tin, 0, sizeof(tin));
  memset(low, 0, sizeof(low));

  for (int i = 0; i < N; i++) {
    if (not tin[i]) dfs(i);
  }
}
