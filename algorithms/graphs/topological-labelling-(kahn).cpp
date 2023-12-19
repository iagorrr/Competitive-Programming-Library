const int MAXN(1'00'000);
int OUTCNT[MAXN];
vi2d GIN(MAXN);
int N;

vi toposort() {
  vi order;
  priority_queue<int> q;

  for (int i = 0; i < N; i++)
    if (!OUTCNT[i]) q.emplace(i);

  while (!q.empty()) {
    auto u = q.top();
    q.pop();
    order.emplace_back(u);
    for (auto v : GIN[u]) {
      OUTCNT[v]--;
      if (OUTCNT[v] == 0) q.emplace(v);
    }
  }

  reverse(all(order));
  return len(order) == N ? order : vi();
}
