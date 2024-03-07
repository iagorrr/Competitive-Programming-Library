const int maxn(3'00'000);
int tin[maxn], low[maxn], comp[maxn], qtdcomps, clk;
vi g[maxn], stck;
int n;
void dfs(int u, int p = -1) {
  low[u] = tin[u] = ++clk;
  stck.emplace_back(u);

  bool flagParent = false;
  for (auto v : g[u]) {
    if (!tin[v]) {
      dfs(v, u);
      low[u] = min(low[u], low[v]);
    } else {
      if (v != p)
        low[u] = min(low[u], tin[v]);
      else {
        if (flagParent)
          low[u] = min(low[u], tin[v]);
        else
          flagParent = true;
      }
    }
  }

  if (low[u] == tin[u]) {
    int v2;
    do {
      v2 = stck.back();
      comp[v2] = qtdcomps;
      stck.pop_back();
    } while (v2 != u);
    qtdcomps++;
  }
}

void label2CC() {
  memset(comp, -1, sizeof(int) * n);

  for (int i = 0; i < n; i++) {
    if (comp[i] == -1) dfs(i);
  }
}
