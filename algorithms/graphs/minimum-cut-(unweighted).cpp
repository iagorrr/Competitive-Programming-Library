const ll oo = 1e17;

ll bfs(int s, int t, vi2d &g, vll2d &capacity, vi &parent) {
  fill(all(parent), -1);
  parent[s] = -2;
  queue<pair<ll, int>> q;
  q.push({oo, s});

  while (!q.empty()) {
    auto [flow, cur] = q.front();
    q.pop();

    for (auto next : g[cur]) {
      if (parent[next] == -1 and capacity[cur][next]) {
        parent[next] = cur;
        ll new_flow = min(flow, capacity[cur][next]);
        if (next == t) return new_flow;
        q.push({new_flow, next});
      }
    }
  }

  return 0ll;
}

ll maxflow(int s, int t, int n, vi2d &g, vll2d &capacity) {
  ll flow = 0;
  vi parent(n);
  ll new_flow;

  while ((new_flow = bfs(s, t, g, capacity, parent))) {
    flow += new_flow;
    int cur = t;
    while (cur != s) {
      int prev = parent[cur];
      capacity[prev][cur] -= new_flow;
      capacity[cur][prev] += new_flow;
      cur = prev;
    }
  }

  return flow;
}
void dfs(int u, vi2d &g, vll2d &capacity, vc &visited) {
  visited[u] = true;

  for (auto v : g[u]) {
    if (capacity[u][v] > 0 and not visited[v]) {
      dfs(v, g, capacity, visited);
    }
  }
}

vii mincut(vii &edges, int s, int t, int n, bool directed = false) {
  vll2d capacity(n, vll(n));
  vi2d g(n);
  for (auto &[u, v] : edges) {
    g[u].eb(v);
    capacity[u][v] += 1;
    if (not directed) {
      g[v].eb(u);
      capacity[v][u] += 1;
    }
  }

  maxflow(0, n - 1, n, g, capacity);
  vc vis(n);
  dfs(0, g, capacity, vis);

  vii removed;
  for (auto &[u, v] : edges) {
    if ((vis[u] and not vis[v]) or (vis[v] and not vis[u]))
      removed.emplace_back(u, v);
  }

  return removed;
}
