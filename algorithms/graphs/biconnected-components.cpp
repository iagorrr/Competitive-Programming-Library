const int maxn(5'00'000);
int tin[maxn], stck[maxn], bcc_cnt, n, top = 0, timer = 1;
vector<int> g[maxn], nodes[maxn];

int tarjan(int u, int p = -1) {
  int lowu = tin[u] = timer++;
  int son_cnt = 0;
  stck[++top] = u;
  for (auto v : g[u]) {
    if (!tin[v]) {
      son_cnt++;
      int lowx = tarjan(v, u);
      lowu = min(lowu, lowx);
      if (lowx >= tin[u]) {
        while (top != -1 && stck[top + 1] != v)
          nodes[bcc_cnt].emplace_back(stck[top--]);
        nodes[bcc_cnt++].emplace_back(u);
      }
    } else {
      lowu = min(lowu, tin[v]);
    }
  }

  if (p == -1 && son_cnt == 0) {
    nodes[bcc_cnt++].emplace_back(u);
  }

  return lowu;
}

void build_bccs() {
  timer = 1;
  top = -1;
  memset(tin, 0, sizeof(int) * n);
  for (int i = 0; i < n; i++) nodes[i] = {};
  bcc_cnt = 0;

  for (int u = 0; u < n; u++)
    if (!tin[u]) tarjan(u);
}
