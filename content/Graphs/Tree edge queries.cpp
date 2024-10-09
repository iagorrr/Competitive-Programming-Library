template <typename T = ll, auto E = 0,
          auto F = [](ll a, ll b) { return max(a, b); }>
struct TEQ {
  const int LOG = 20;
  using Graph = vector<vector<pair<ll, int>>>;
  int n;
  vector<int> h;
  vector<vector<int>> par;
  vector<vector<T>> ed;
  TEQ(const Graph& g, int root = 0)
      : n(size(g)),
        h(n, -1),
        par(n, vector<int>(LOG + 1, root)),
        ed(n, vector<T>(LOG + 1, E)) {
    h[root] = 0, dfs(root, g);
  }

  void dfs(int u, const Graph& g) {
    for (auto& [w, v] : g[u]) {
      if (h[v] == -1) {
        h[v] = h[u] + 1, par[v][0] = u, ed[v][0] = w;
        for (int k = 0, p; k < LOG; k++) {
          p = par[v][k];
          par[v][k + 1] = par[p][k];
          ed[v][k + 1] = F(ed[v][k], ed[p][k]);
        }
        dfs(v, g);
      }
    }
  }

  pair<int, T> up(int u, int dis) {
    T res = E;
    for (int k = 0; k <= LOG; k++) {
      if (dis & (1 << k)) {
        res = F(res, ed[u][k]);
        u = par[u][k];
      }
    }
    return {u, res};
  }

  pair<int, T> lca(int u, int v) {
    if (h[u] > h[v]) swap(u, v);
    T res = E;
    tie(v, res) = up(v, h[v] - h[u]);
    if (v == u) return {v, res};
    for (int k = LOG; ~k; k--) {
      if (par[u][k] != par[v][k]) {
        res = F(res, ed[v][k]);
        res = F(res, ed[u][k]);
        u = par[u][k], v = par[v][k];
      }
    }
    res = F(res, ed[v][0]);
    res = F(res, ed[u][0]);
    return {par[v][0], res};
  }
};
