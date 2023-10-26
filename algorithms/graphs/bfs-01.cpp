vector<pair<ll, int>> adj[maxn];
ll dists[maxn];
int s, n;
void bfs_01() {
  fill(dists, dists + n, oo);
  dist[s] = 0;

  deque<int> q;
  q.emplace_back(s);

  while (not q.empty()) {
    auto u = q.front();
    q.pop_front();

    for (auto [v, w] : adj[u]) {
      if (dist[v] <= dist[u] + w) continue;
      dist[v] = dist[u] + w;
      w ? q.emplace_back(v) : q.emplace_front(v);
    }
  }
}
