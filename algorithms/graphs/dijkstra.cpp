ll __inf = LLONG_MAX >> 5;
vll dijkstra(const vector<vector<pll>> &g, ll n) {
  priority_queue<pll, vector<pll>, greater<pll>> pq;
  vll dist(n, __inf);
  vector<char> vis(n);
  pq.emplace(0, 0);
  dist[0] = 0;
  while (!pq.empty()) {
    auto [d1, v] = pq.top();
    pq.pop();
    if (vis[v])
      continue;
    vis[v] = true;

    for (auto [d2, u] : g[v]) {
      if (dist[u] > d1 + d2) {
        dist[u] = d1 + d2;
        pq.emplace(dist[u], u);
      }
    }
  }
  return dist;
}
