struct maxflow {
  int n;
  vi2d g;
  vll2d capacity;
  vi parent;

  maxflow(int _n) : n(_n), g(n), capacity(n, vll(n)), parent(n) {}

  void add(int u, int v, ll c, bool set = true) {
    g[u].emplace_back(v);
    g[v].emplace_back(u);
    capacity[u][v] = capacity[u][v] * (!set) + c;
  }

  ll bfs(int s, int t) {
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

  ll flow(int s, int t) {
    ll flow = 0;
    ll new_flow;

    while ((new_flow = bfs(s, t))) {
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
};
