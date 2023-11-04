vi2d G;
int N, M;

bool check() {
  vi side(N, -1);
  queue<int> q;
  for (int st = 0; st < N; st++) {
    if (side[st] == -1) {
      q.emplace(st);
      side[st] = 0;
      while (not q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : G[u]) {
          if (side[v] == -1) {
            side[v] = side[u] ^ 1;
            q.push(v);
          } else if (side[u] == side[v])
            return false;
        }
      }
    }
  }
  return true;
}
