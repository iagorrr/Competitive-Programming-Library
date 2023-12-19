const int MAXN(2'00'000);
int INCNT[MAXN];
vi2d GOUT(MAXN);
int N;

vi toposort() {
  vi order;
  queue<int> q;

  for (int i = 0; i < N; i++)
    if (!INCNT[i]) q.emplace(i);

  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    order.emplace_back(u);
    for (auto v : GOUT[u]) {
      INCNT[v]--;
      if (INCNT[v] == 0) q.emplace(v);
    }
  }

  return len(order) == N ? order : vi();
}
