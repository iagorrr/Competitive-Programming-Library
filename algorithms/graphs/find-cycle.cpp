bool dfs(int v, int p, vi2d &g, vc &vis, vi &par, int &s, int &e) {
  vis[v] = true;
  for (int u : g[v]) {
    if (u == p) continue;
    if (vis[u]) {
      e = v;
      s = u;
      return true;
    }
    par[u] = v;
    if (dfs(u, par[u], g, vis, par, s, e)) return true;
  }
  return false;
}

vi find_cycle(vi2d &g, int n) {
  vc vis(n, false);
  vi par(n, -1);
  int end, start = -1;

  for (int v = 0; v <= n - 1; v++) {
    if (!vis[v] and dfs(v, par[v], g, vis, par, start, end)) break;
  }

  if (start == -1) {
    return {};
  } else {
    vi cycle;
    cycle.push_back(start);
    for (int v = end; v != start; v = par[v]) cycle.push_back(v);
    cycle.push_back(start);

    return cycle;
  }
}
