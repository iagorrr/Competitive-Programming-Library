struct maxflow {
  int n;
  vi2d g;
  vll2d cps;
  vi ps;
  vector<vector<char>> isedge;

  maxflow(int _n)
    : n(_n),
      g(n),
      cps(n, vll(n)),
      ps(n),
      isedge(n, vc(n)) {}

  void add(int u, int v, ll c, bool set = true) {
    g[u].emplace_back(v);
    g[v].emplace_back(u);
    cps[u][v] = cps[u][v] * (!set) + c;
    isedge[u][v] = true;
  }

  ll bfs(int s, int t) {
    fill(all(ps), -1);
    ps[s] = -2;
    queue<pair<ll, int>> q;
    q.emplace(oo, s);

    while (!q.empty()) {
      auto [flow, cur] = q.front();
      q.pop();

      for (auto next : g[cur]) {
        if (ps[next] == -1 and cps[cur][next]) {
          ps[next] = cur;
          ll new_flow = min(flow, cps[cur][next]);
          if (next == t) return new_flow;
          q.emplace(new_flow, next);
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
        int prev = ps[cur];
        cps[prev][cur] -= new_flow;
        cps[cur][prev] += new_flow;
        cur = prev;
      }
    }

    return flow;
  }

  vector<pii> get_used() {
    vector<pii> used;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (isedge[i][j] and cps[i][j] == 0)
          used.emplace_back(i, j);
      }
    }
    return used;
  }
};
