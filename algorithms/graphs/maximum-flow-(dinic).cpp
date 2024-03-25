struct Dinic {
  struct Edge {
    int to, rev;
    long long c, oc;
    long long flow() {
      return max(oc - c, 0LL);
    }  // if you need flows
  };
  vector<int> lvl, ptr, q;
  vector<vector<Edge>> adj;
  Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
  void addEdge(int a, int b, long long c,
               long long rcap = 0) {
    adj[a].push_back({b, (int)adj[b].size(), c, c});
    adj[b].push_back(
      {a, (int)adj[a].size() - 1, rcap, rcap});
  }
  long long dfs(int v, int t, long long f) {
    if (v == t || !f) return f;
    for (int& i = ptr[v]; i < (int)adj[v].size(); i++) {
      Edge& e = adj[v][i];
      if (lvl[e.to] == lvl[v] + 1)
        if (long long p = dfs(e.to, t, min(f, e.c))) {
          e.c -= p, adj[e.to][e.rev].c += p;
          return p;
        }
    }
    return 0;
  }
  long long calc(int s, int t) {
    long long flow = 0;
    q[0] = s;
    for (int L = 0; L < 31; L++)
      do {  // 'int L=30' maybe faster for random data
        lvl = ptr = vector<int>(q.size());
        int qi = 0, qe = lvl[s] = 1;
        while (qi < qe && !lvl[t]) {
          int v = q[qi++];
          for (Edge e : adj[v])
            if (!lvl[e.to] && e.c >> (30 - L))
              q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
        }
        while (long long p = dfs(s, t, LLONG_MAX))
          flow += p;
      } while (lvl[t]);
    return flow;
  }
  bool leftOfMinCut(int a) { return lvl[a] != 0; }
};
