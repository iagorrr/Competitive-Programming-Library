int tin[MAXN], low[MAXN], timer, N;
char vis[MAXN];
vi2d G(MAXN);
vector<pii> bridges;

void dfs(int u, int p = -1) {
  vis[u] = true;
  tin[u] = low[u] = timer++;

  for (auto v : G[u]) {
    if (v == p) continue;
    if (vis[v]) {
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
  timer = 0;
  memset(vis, 0, sizeof(vis));
  memset(tin, -1, sizeof(tin));
  memset(low, -1, sizeof(low));
  bridges.clear();

  for (int i = 0; i < N; i++) {
    if (not vis[i]) dfs(i);
  }
}
