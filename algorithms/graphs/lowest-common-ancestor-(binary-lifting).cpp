const int MAXLOG2 = 20, MAXN(2'00'000);
int N;
int G[MAXN];
int depth[MAXN];
int up[MAXN][MAXLOG2 + 1];
vi GT[MAXN];

void build(int u = 0) {
  for (int i = 1; i <= MAXLOG2; i++)
    up[u][i] = up[up[u][i - 1]][i - 1];

  for (int v : GT[u])
    if (v != up[u][0]) {
      depth[v] = depth[up[v][0] = u] + 1;
      build(v);
    }
}

int jump(int u, ll k) {
  for (ll i = 0; i <= MAXLOG2; i++)
    if (k & (1ll << i)) u = up[u][i];

  return u;
}

int lca(int a, int b) {
  if (depth[a] < depth[b]) swap(a, b);

  a = jump(a, depth[a] - depth[b]);

  if (b == a) return a;

  for (int i = MAXLOG2; i >= 0; i--) {
    int at = up[a][i], bt = up[b][i];
    if (at != bt) a = at, b = bt;
  }

  return up[a][0];
}
