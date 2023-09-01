pll mostDistantFrom(const vector<vll> &adj, ll n, ll root) {
  // 0 indexed
  ll mostDistantNode = root;
  ll nodeDistance = 0;
  queue<pll> q;
  vector<char> vis(n);
  q.emplace(root, 0);
  vis[root] = true;
  while (!q.empty()) {
    auto [node, dist] = q.front();
    q.pop();
    if (dist > nodeDistance) {
      nodeDistance = dist;
      mostDistantNode = node;
    }
    for (auto u : adj[node]) {
      if (!vis[u]) {
        vis[u] = true;
        q.emplace(u, dist + 1);
      }
    }
  }
  return {mostDistantNode, nodeDistance};
}
ll twoNodesDist(const vector<vll> &adj, ll n, ll a, ll b) {
  // 0 indexed
  queue<pll> q;
  vector<char> vis(n);
  q.emplace(a, 0);
  while (!q.empty()) {
    auto [node, dist] = q.front();
    q.pop();
    if (node == b) {
      return dist;
    }
    for (auto u : adj[node]) {
      if (!vis[u]) {
        vis[u] = true;
        q.emplace(u, dist + 1);
      }
    }
  }
  return -1;
}
ll tree_diameter(const vector<vll> &adj, ll n) {
  // 0 indexed !!!
  auto [node1, dist1] = mostDistantFrom(adj, n, 0);      // O(V)
  auto [node2, dist2] = mostDistantFrom(adj, n, node1);  // O(V)
  auto diameter = twoNodesDist(adj, n, node1, node2);    // O(V)
  return diameter;
}
