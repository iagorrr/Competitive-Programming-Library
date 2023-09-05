vll dijkstra(const vector<vector<pll>> &g, int n, int s) {
  priority_queue<pll, vector<pll>, greater<pll>> pq;
  vll dist(n + 1, oo);
  vector<char> vis(n + 1);
  pq.emplace(0, s);
  dist[s] = 0;
  while (!pq.empty()) {
    auto [d1, v] = pq.top();
    pq.pop();
    if (vis[v]) continue;
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
