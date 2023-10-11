struct DisjointPaths {
  int n;
  vi2d g, capacity;
  vector<vc> isedge;

  DisjointPaths(int _n) : n(_n), g(n), capacity(n, vi(n)), isedge(n, vc(n)) {}

  void add(int u, int v, int w = 1) {
    g[u].emplace_back(v);
    g[v].emplace_back(u);
    capacity[u][v] += w;
    isedge[u][v] = true;
  }

  // finds the new flow to insert
  int bfs(int s, int t, vi &parent) {
    fill(all(parent), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
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

    return 0;
  }

  int maxflow(int s, int t) {
    int flow = 0;
    vi parent(n);
    int new_flow;

    while ((new_flow = bfs(s, t, parent))) {
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

  // build the distinct routes based in the capacity set by maxflow
  void dfs(int u, int t, vc2d &vis, vi &route, vi2d &routes) {
    route.eb(u);
    if (u == t) {
      routes.emplace_back(route);
      route.pop_back();
      return;
    }

    for (auto &v : g[u]) {
      if (capacity[u][v] == 0 and isedge[u][v] and not vis[u][v]) {
        vis[u][v] = true;
        dfs(v, t, vis, route, routes);
        route.pop_back();
        return;
      }
    }
  }

  vi2d disjoint_paths(int s, int t) {
    int mf = maxflow(s, t);
    vi2d routes;
    vi route;
    vc2d vis(n, vc(n));
    for (int i = 0; i < mf; i++) dfs(s, t, vis, route, routes);
    return routes;
  }
};
