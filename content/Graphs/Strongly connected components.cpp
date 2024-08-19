/*8<
  @Title:

    Strongly Connected Components (struct)

  @Description:

    Find the connected component for each edge
    (already in a topological order), some
    additional functions are also provided.

  @Time:

    Build: $O(V+E)$
>8*/

struct SCC {
  int n, num_sccs;
  vi2d adj;
  vi scc_id;

  SCC(int _n)
      : n(_n),
        num_sccs(0),
        adj(n),
        scc_id(n, -1) {}

  void add_edge(int u, int v) { adj[u].eb(v); }

  void find_sccs() {
    int timer = 1;
    vi tin(n), st;
    st.reserve(n);
    function<int(int)> dfs = [&](int u) -> int {
      int low = tin[u] = timer++, siz = len(st);
      st.eb(u);
      for (int v : adj[u])
        if (scc_id[v] < 0)
          low =
              min(low, tin[v] ? tin[v] : dfs(v));
      if (tin[u] == low) {
        rep(i, siz, len(st)) scc_id[st[i]] =
            num_sccs;
        st.resize(siz);
        num_sccs++;
      }
      return low;
    };

    for (int i = 0; i < n; i++)
      if (!tin[i]) dfs(i);
  }

  vector<set<int>> build_gscc() {
    vector<set<int>> gscc;
    for (int i = 0; i < len(adj); ++i)
      for (auto j : adj[i])
        if (scc_id[i] != scc_id[j])
          gscc[scc_id[i]].emplace(scc_id[j]);
    return gscc;
  }

  vi2d per_comp() {
    vi2d ret(num_sccs);
    rep(i, 0, n) ret[scc_id[i]].eb(i);
    reverse(all(
        ret));  // already in topological order ;)
    return ret;
  }
};
