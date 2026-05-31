/*8<
  @Title: Maximum flow (Dinic)

  @Description:

    Finds the \textbf{maximum flow} from source
    $s$ to sink $t$. By the \textbf{Max-Flow
    Min-Cut theorem}, the maximum flow equals
    the minimum cut. Use \texttt{leftOfMinCut}
    or \texttt{minCutEdges} after
    \texttt{maxFlow} to recover the cut.

  @Usage:

    \begin{compactitem}
      \item \textbf{addEdge(a, b, c, rc):} adds
      a directed edge $a \to b$ with capacity
      $c$ and reverse capacity $rc$ (use
      $rc = c$ for undirected edges).

      \item \textbf{maxFlow(s, t):} returns
      maximum flow; updates residual in-place.

      \item \textbf{leftOfMinCut(v):} returns
      true if $v$ is on the source side of the
      min-cut (call after \texttt{maxFlow}).

      \item \textbf{minCutEdges():} returns the
      directed edges $(u, v)$ crossing the
      min-cut (call after \texttt{maxFlow}).
    \end{compactitem}

  @Time:

    General $O(V^2 \cdot E)$. Unit-capacity
    graphs where every vertex has in- or
    out-degree $\le 1$: $O(E \cdot \sqrt{V})$.

  @Warning:

    Shuffling each vertex's edge list may help
    escape worst-case inputs.
    \texttt{leftOfMinCut} and
    \texttt{minCutEdges} are only valid after
    \texttt{maxFlow} completes.
>8*/
struct Dinic {
    struct Edge {
        int to, rev;
        ll c, oc;
        ll flow() { return max(oc - c, 0LL); }
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
            do {  // 'int L=30' maybe faster for random data
                lvl = ptr = vi(len(q));
                int qi = 0, qe = lvl[s] = 1;
                while (qi < qe && !lvl[t]) {
                    int v = q[qi++];
                    for (Edge e : adj[v])
                        if (!lvl[e.to] && e.c >> (30 - L))
                            q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
                }
                while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
            } while (lvl[t]);
        }
        return flow;
    }

    bool leftOfMinCut(int a) { return lvl[a] != 0; }

    vector<pair<int, int>> minCutEdges() {
        vector<pair<int, int>> cut;
        for (int u = 0; u < len(adj); u++)
            for (auto &e : adj[u])
                if (lvl[u] && !lvl[e.to] && e.oc > 0) cut.pb({u, e.to});
        return cut;
    }
};
