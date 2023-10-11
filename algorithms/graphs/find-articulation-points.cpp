
const int MAXN(100);
int N;
vi2d G;
int timer;
char vis[MAXN];
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
