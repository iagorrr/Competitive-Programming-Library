bool bfs(const ll n, int s, const vector<vll> &adj, vll &color) {
  queue<ll> q;
  q.push(s);
  color[s] = 0;
  bool isBipartite = true;
  while (!q.empty() && isBipartite) {
    ll u = q.front();
    q.pop();
    for (auto &v : adj[u]) {
      if (color[v] == INF) {
        color[v] = 1 - color[u];
        q.push(v);
      } else if (color[v] == color[u]) {
        return false;
      }
    }
  }
  return true;
}

bool checkBipartite(int n, const vll2d &adj) {
  vll color(n, oo);
  for (int i = 0; i < n; i++) {
    if (color[i] != oo) {
      if (not bfs(n, adj, color)) return false;
    }
  }
  return true;
}
