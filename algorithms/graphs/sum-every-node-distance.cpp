
void getRoot(int u, int p, vi2d &g, vll2d &sd, vi2d &sc, vll &d, vll &cnt) {
  for (int i = 0; i < len(g[u]); i++) {
    int v = g[u][i];
    if (v == p) continue;
    getRoot(v, u, g, sd, sc, d, cnt);
    sd[u][i] = 1 + d[v] + cnt[v];
    sc[u][i] = cnt[v] + 1;
    d[u] += 1 + d[v] + cnt[v];
    cnt[u] += cnt[v] + 1;
  }
}

void dfs(int u, int p, vi2d &g, vll2d &sd, vi2d &scnt, vll &d, vll &cnt,
         vll &ansd, int n) {
  for (int i = 0; i < len(g[u]); i++) {
    int v = g[u][i];
    if (v == p) continue;

    ansd[v] = ansd[u] - scnt[u][i] + (n - scnt[u][i]);
    dfs(v, u, g, sd, scnt, d, cnt, ansd, n);
  }
}
vll fromToAll(vi2d &g, int n) {
  vll2d sd(n);
  vi2d scnt(n);
  vll d(n);
  vll cnt(n);
  for (int i = 0; i < n; i++) {
    sd[i] = vll(len(g[i]));
    scnt[i] = vi(len(g[i]));
  }
  getRoot(0, -1, g, sd, scnt, d, cnt);

  vll ansdist(n);
  ansdist[0] = d[0];
  dfs(0, -1, g, sd, scnt, d, cnt, ansdist, n);
  return ansdist;
}
