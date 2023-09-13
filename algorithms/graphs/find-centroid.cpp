void dfs(int u, int p, int n, vi2d &g, vi &sz, vi &centroid) {
  sz[u] = 1;

  bool iscentroid = true;
  for (auto v : g[u])
    if (v != p) {
      dfs(v, u, n, g, sz, centroid);
      if (sz[v] > n / 2) iscentroid = false;
      sz[u] += sz[v];
    }

  if (n - sz[u] > n / 2) iscentroid = false;
  if (iscentroid) centroid.eb(u);
}
vi getCentroid(vi2d &g, int n) {
  vi centroid;
  vi sz(n);
  dfs(0, -1, n, g, sz, centroid);
  return centroid;
}
