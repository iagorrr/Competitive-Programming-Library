// O(V)
bool checkBipartite(const ll n, const vector<vll> &adj) {
  ll s = 0;
  queue<ll> q;
  q.push(s);
  vll color(n, INF);
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
