/*8<
  @Title: Maximum flow (Dinic)

  @Description:

    Finds the \textbf{maximum flow} in a graph
    network, given the \textbf{source $s$} and
    the \textbf{sink $t$}. Add edge from $a$ to
    $b$ with capcity $c$.

  @Time:

    In general $O(E \cdot V^2)$, if every capacity
    is 1, and every vertice has in degree equal 1
    or out degree equal 1 then $O(E \cdot
    \sqrt{V})$,

  @Warning:

    Suffle the edges list for every vertice may
    take you out of the worst case
>8*/
struct Dinic {
  struct Edge {
    int to, rev;
    ll c, oc;
    ll flow() {
      return max(oc - c, 0LL);
    }  // if you need flows
  };

  vi lvl, ptr, q;
  vector<vector<Edge>> adj;

  Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}

  void addEdge(int a, int b, ll c, ll rcap = 0) {
    adj[a].pb({b, len(adj[b]), c, c});
    adj[b].pb({a, len(adj[a]) - 1, rcap, rcap});
  }

  ll dfs(int v, int t, ll f) {
    if (v == t || !f) return f;
    for (int &i = ptr[v]; i < len(adj[v]); i++) {
      Edge &e = adj[v][i];
      if (lvl[e.to] == lvl[v] + 1)
        if (ll p = dfs(e.to, t, min(f, e.c))) {
          e.c -= p, adj[e.to][e.rev].c += p;
          return p;
        }
    }
    return 0;
  }

  ll maxFlow(int s, int t) {
    ll flow = 0;
    q[0] = s;
    rep(L, 0, 31) {
      do {  // 'int L=30' maybe faster for random
            // data
        lvl = ptr = vi(len(q));
        int qi = 0, qe = lvl[s] = 1;
        while (qi < qe && !lvl[t]) {
          int v = q[qi++];
          for (Edge e : adj[v])
            if (!lvl[e.to] && e.c >> (30 - L))
              q[qe++] = e.to,
              lvl[e.to] = lvl[v] + 1;
        }

        while (ll p = dfs(s, t, LLONG_MAX))
          flow += p;
      } while (lvl[t]);
    }
    return flow;
  }

  bool leftOfMinCut(int a) { return lvl[a] != 0; }
};
