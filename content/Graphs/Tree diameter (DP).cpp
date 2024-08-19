const int MAXN(1 '000' 000);
int N;
vi G[MAXN];

int diameter, toLeaf[MAXN];
void calcDiameter(int u = 0, int p = -1) {
  int d1, d2;
  d1 = d2 = -1;

  for (auto v : G[u]) {
    if (v != p) {
      calcDiameter(v, u);
      d1 = max(d1, toLeaf[v]);
      tie(d1, d2) = minmax({d1, d2});
    }
  }
  toLeaf[u] = d2 + 1;
  diameter = max(diameter, d1 + d2 + 2);
}
