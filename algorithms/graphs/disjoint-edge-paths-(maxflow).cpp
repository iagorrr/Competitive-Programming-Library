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

void dfs(int u, int t, vi2d &g, vc2d &vis, vc2d &isedge, vll2d &capacity,
         vi &route, vi2d &routes) {
  route.eb(u);
  if (u == t) {
    routes.emplace_back(route);
    route.pop_back();
    return;
  }
  for (auto &v : g[u]) {
    if (capacity[u][v] == 0 and isedge[u][v] and not vis[u][v]) {
      vis[u][v] = true;
      dfs(v, t, g, vis, isedge, capacity, route, routes);
      route.pop_back();
      return;
    }
  }
}
vi2d disjoint_paths(vi2d &g, vll2d &capacity, vc2d &isedge, int s, int t,
                    int n) {
  ll mf = maxflow(s, t, n, g, capacity);
  vi2d routes;
  vi route;
  vc2d vis(n + 1, vc(n + 1));
  for (int i = 0; i < (int)mf; i++)
    dfs(s, t, g, vis, isedge, capacity, route, routes);
  return routes;
}
