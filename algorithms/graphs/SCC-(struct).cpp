struct SCC {
  int num_sccs = 0;
  vi scc_id;
  vector<set<ll>> gscc;

  SCC(const vi2d& adj)
    : scc_id(len(adj), -1), gscc(len(adj)) {
    int n = len(adj), timer = 1;
    vi tin(n), st;
    st.reserve(n);
    auto dfs = [&](auto&& self, int u) -> int {
      int low = tin[u] = timer++, siz = len(st);
      st.push_back(u);
      for (int v : adj[u])
        if (scc_id[v] < 0)
          low = min(low, tin[v] ? tin[v] : self(self, v));
      if (tin[u] == low) {
        for (int i = siz; i < len(st); i++)
          scc_id[st[i]] = num_sccs;
        st.resize(siz);
        num_sccs++;
      }
      return low;
    };
    for (int i = 0; i < n; i++)
      if (!tin[i]) dfs(dfs, i);

    for (int i = 0; i < len(adj); ++i)
      for (auto j : adj[i])
        if (scc_id[i] != scc_id[j])
          gscc[scc_id[i]].emplace(scc_id[j]);
  }
};
