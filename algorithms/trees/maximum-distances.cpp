pll mostDistantFrom(const vector<vll> &adj, ll n, ll root) {
  // O(V)
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
  queue<pll> q;
  vector<char> vis(n);
  q.emplace(a, 0);
  while (!q.empty()) {
    auto [node, dist] = q.front();
    q.pop();
    if (node == b) return dist;
    for (auto u : adj[node]) {
      if (!vis[u]) {
        vis[u] = true;
        q.emplace(u, dist + 1);
      }
    }
  }
  return -1;
}

tuple<ll, ll, ll> tree_diameter(const vector<vll> &adj, ll n) {
  // returns two points of the diameter and the diameter itself
  auto [node1, dist1] = mostDistantFrom(adj, n, 0);      // O(V)
  auto [node2, dist2] = mostDistantFrom(adj, n, node1);  // O(V)
  auto diameter = twoNodesDist(adj, n, node1, node2);    // O(V)
  return make_tuple(node1, node2, diameter);
}

vll everyDistanceFromNode(const vector<vll> &adj, ll n, ll root) {
  // Single Source Shortest Path, from a given root
  queue<pair<ll, ll>> q;
  vll ans(n, -1);
  ans[root] = 0;
  q.emplace(root, 0);
  while (!q.empty()) {
    auto [u, d] = q.front();
    q.pop();

    for (auto w : adj[u]) {
      if (ans[w] != -1) continue;
      ans[w] = d + 1;
      q.emplace(w, d + 1);
    }
  }
  return ans;
}

vll maxDistances(const vector<vll> &adj, ll n) {
  auto [node1, node2, diameter] = tree_diameter(adj, n);   // O(3V)
  auto distances1 = everyDistanceFromNode(adj, n, node1);  // O(V)
  auto distances2 = everyDistanceFromNode(adj, n, node2);  // O(V)
  vll ans(n);
  for (int i = 0; i < n; ++i)
    ans[i] = max(distances1[i], distances2[i]);  // O(V)
  return ans;
}
