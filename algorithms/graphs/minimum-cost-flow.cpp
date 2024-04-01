template <typename T>
struct mcmf {
  struct edge {
    int to, rev, flow, cap;
    bool res;  // if it's a reverse edge
    T cost;    // cost per unity of flow
    edge()
      : to(0),
        rev(0),
        flow(0),
        cap(0),
        cost(0),
        res(false) {}
    edge(int to_, int rev_, int flow_, int cap_, T cost_,
         bool res_)
      : to(to_),
        rev(rev_),
        flow(flow_),
        cap(cap_),
        res(res_),
        cost(cost_) {}
  };

  vector<vector<edge>> g;
  vector<int> par_idx, par;
  T inf;
  vector<T> dist;

  mcmf(int n)
    : g(n),
      par_idx(n),
      par(n),
      inf(numeric_limits<T>::max() / 3) {}

  void add(int u, int v, int w, T cost) {
    edge a = edge(v, (int)g[v].size(), 0, w, cost, false);
    edge b = edge(u, (int)g[u].size(), 0, 0, -cost, true);

    g[u].emplace_back(a);
    g[v].emplace_back(b);
  }

  /* don't code this if there isn't negative cyles ! */
  vector<T> spfa(int s) {
    deque<int> q;
    vector<char> is_inside(g.size(), 0);
    dist = vector<T>(g.size(), inf);

    dist[s] = 0;
    q.push_back(s);
    is_inside[s] = true;

    while (!q.empty()) {
      int v = q.front();
      q.pop_front();
      is_inside[v] = false;

      for (int i = 0; i < (int)g[v].size(); i++) {
        auto [to, rev, flow, cap, res, cost] = g[v][i];
        if (flow < cap and dist[v] + cost < dist[to]) {
          dist[to] = dist[v] + cost;

          if (is_inside[to]) continue;
          if (!q.empty() and dist[to] > dist[q.front()])
            q.push_back(to);
          else
            q.push_front(to);
          is_inside[to] = true;
        }
      }
    }
    return dist;
  }

  bool dijkstra(int s, int t, vector<T>& pot) {
    priority_queue<pair<T, int>, vector<pair<T, int>>,
                   greater<>>
      q;
    dist = vector<T>(g.size(), inf);
    dist[s] = 0;
    q.emplace(0, s);
    while (q.size()) {
      auto [d, v] = q.top();
      q.pop();
      if (dist[v] < d) continue;
      for (int i = 0; i < (int)g[v].size(); i++) {
        auto [to, rev, flow, cap, res, cost] = g[v][i];
        cost += pot[v] - pot[to];
        if (flow < cap and dist[v] + cost < dist[to]) {
          dist[to] = dist[v] + cost;
          q.emplace(dist[to], to);
          par_idx[to] = i, par[to] = v;
        }
      }
    }

    return dist[t] < inf;
  }

  pair<int, T> min_cost_flow(int s, int t, int flow) {
    vector<T> pot((int)g.size(), 0);

    /* comment or remove this line if there isn't negative
     * cyles*/
    // pot = spfa(s);

    int f = 0;
    T ret = 0;
    while (f < flow and dijkstra(s, t, pot)) {
      for (int i = 0; i < (int)g.size(); i++)
        if (dist[i] < inf) pot[i] += dist[i];

      int mn_flow = flow - f, u = t;
      while (u != s) {
        mn_flow =
          min(mn_flow, g[par[u]][par_idx[u]].cap -
                         g[par[u]][par_idx[u]].flow);
        u = par[u];
      }

      ret += pot[t] * mn_flow;

      u = t;
      while (u != s) {
        g[par[u]][par_idx[u]].flow += mn_flow;
        g[u][g[par[u]][par_idx[u]].rev].flow -= mn_flow;
        u = par[u];
      }

      f += mn_flow;
    }

    return make_pair(f, ret);
  }
};
