/*8<
  @Title:

    D`Escopo-Pape

  @Description:

    Is a single source shortest path that works
    faster than Dijkstra's algorithm and the
    Bellman-Ford algorithm in most cases, and will
    also work for negative edges. However not for
    negative cycles. There exists cases where it
    runs in exponential time.

  @Usage:

    Returns a pair containing two vectors, the
    first one with the distance from $s$ to every
    other node, and another one with the ancestor
    of each node, note that the ancestor of $s$
    is $-1$

>8*/

using Edge = pair<ll, int>;
using Adj = vector<vector<Edge>>;

pair<vll, vi> desopo_pape(int s, int n, const Adj &adj) {
  vll ds(n, LLONG_MAX), ps(n, -1);
  ds[s] = 0;
  vi ms(n, 2);
  deque<int> q;
  q.eb(s);
  while (len(q)) {
    int u = q.front();
    q.pop_front();
    ms[u] = 0;
    for (auto [w, v] : adj[u]) {
      if (chmin(ds[v], w + ds[u])) {
        ps[v] = u;
        if (ms[v] == 2)
          ms[v] = 1, q.pb(v);
        else if (ms[v] == 0)
          ms[v] = 1, q.pf(v);
      }
    }
  }
  return {ds, ps};
}
