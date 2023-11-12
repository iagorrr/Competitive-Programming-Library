struct Mincut {
  int n;
  vi2d g;
  vii edges;
  vll2d capacity;
  vi ps, vis;

  Mincut(int _n)
    : n(_n), g(n), capacity(n, vll(n)), ps(n), vis(n) {}

  void add(int u, int v, ll c = 1, bool directed = false,
           bool set = false) {
    edges.emplace_back(u, v);
    g[u].emplace_back(v);

    if (not set)
      capacity[u][v] += c;
    else
      capacity[u][v] = c;

    if (not directed) {
      g[v].emplace_back(u);

      if (not set)
        capacity[v][u] += c;
      else
        capacity[v][u] = c;
    }
  }

  ll bfs(int s, int t) {
    fill(all(ps), -1);
    ps[s] = -2;
    queue<pair<ll, int>> q;
    q.push({oo, s});

    while (!q.empty()) {
      auto [flow, cur] = q.front();
      q.pop();

      for (auto next : g[cur]) {
        if (ps[next] == -1 and capacity[cur][next]) {
          ps[next] = cur;
          ll new_flow = min(flow, capacity[cur][next]);
          if (next == t) return new_flow;
          q.push({new_flow, next});
        }
      }
    }

    return 0ll;
  }

  ll maxflow(int s, int t) {
    ll flow = 0;
    ll new_flow;

    while ((new_flow = bfs(s, t))) {
      flow += new_flow;
      int cur = t;
      while (cur != s) {
        int prev = ps[cur];
        capacity[prev][cur] -= new_flow;
        capacity[cur][prev] += new_flow;
        cur = prev;
      }
    }

    return flow;
  }
  void dfs(int u) {
    vis[u] = true;

    for (auto v : g[u]) {
      if (capacity[u][v] > 0 and not vis[v]) {
        dfs(v);
      }
    }
  }

  vii mincut(int s, int t) {
    maxflow(s, t);
    fill(all(vis), 0);
    dfs(s);

    vii removed;
    for (auto &[u, v] : edges) {
      if ((vis[u] and not vis[v]) or
          (vis[v] and not vis[u]))
        removed.emplace_back(u, v);
    }

    return removed;
  }
};
