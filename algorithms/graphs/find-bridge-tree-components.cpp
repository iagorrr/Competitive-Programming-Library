const int maxn(3'00'000);
int tin[maxn], compId[maxn], qtdComps;
vi g[maxn], stck;
int n;
int dfs(int u, int p = -1) {
  int low = tin[u] = len(stck);
  stck.emplace_back(u);

  bool multEdge = false;
  for (auto v : g[u]) {
    if (v == p and !multEdge) {
      multEdge = 1;
      continue;
    }
    low = min(low, tin[v] == -1 ? dfs(v, u) : tin[v]);
  }

  if (low == tin[u]) {
    for (int i = tin[u]; i < len(stck); i++)
      compId[stck[i]] = qtdComps;
    stck.resize(tin[u]);
    qtdComps++;
  }

  return low;
}

void label2CC() {
  memset(compId, -1, sizeof(int) * n);
  memset(tin, -1, sizeof(int) * n);

  stck.reserve(n);
  for (int i = 0; i < n; i++) {
    if (tin[i] == -1) dfs(i);
  }
}
