const int MAXN(2'00'000);
int N;
vi2d G(MAXN);
int toleaf[MAXN], maxdist[MAXN];

void dfs(int u, int p = -1) {
  int ds1, ds2;
  ds1 = ds2 = -1;
  for (auto v : G[u]) {
    if (v == p) continue;
    if (ds1 > ds2) swap(ds1, ds2);
    dfs(v, u);

    ds1 = max(ds1, toleaf[v]);
  }

  toleaf[u] = max(ds1, ds2) + 1;

  maxdist[u] = 2 + ds1 + ds2;
}

int diameter(int root, int n) {
  dfs(root);

  int d = 0;

  for (int u = 0; u < n; ++u) d = max(d, maxdist[u]);

  return d;
}
