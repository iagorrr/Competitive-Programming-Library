struct SCC {
  int num_sccs = 0;
  vi scc_id;
  SCC(const vi2d& adj) : scc_id(len(adj), -1) {
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
  }
};

vector<array<int, 2>> extra_edges(const vi2d& adj) {
  SCC scc(adj);
  auto scc_id = scc.scc_id;
  auto num_sccs = scc.num_sccs;

  if (num_sccs == 1) return {};

  int n = len(adj);
  vi2d scc_adj(num_sccs);
  vi zero_in(num_sccs, 1);
  for (int u = 0; u < n; u++)
    for (int v : adj[u]) {
      if (scc_id[u] == scc_id[v]) continue;
      scc_adj[scc_id[u]].eb(scc_id[v]);
      zero_in[scc_id[v]] = 0;
    }

  vi vis(num_sccs);
  auto dfs = [&](auto&& self, int u) {
    if (empty(scc_adj[u])) return u;
    for (int v : scc_adj[u])
      if (!vis[v]) {
        vis[v] = 1;
        int zero_out = self(self, v);
        if (zero_out != -1) return zero_out;
      }
    return -1;
  };

  vector<array<int, 2>> edges;
  vi in_unused;
  for (int i = 0; i < num_sccs; i++)
    if (zero_in[i]) {
      vis[i] = 1;
      int zero_out = dfs(dfs, i);
      if (zero_out != -1)
        edges.push_back({zero_out, i});
      else
        in_unused.push_back(i);
    }

  for (int i = 1; i < len(edges); i++)
    swap(edges[i][0], edges[i - 1][0]);

  for (int i = 0; i < num_sccs; i++)
    if (empty(scc_adj[i]) && !vis[i]) {
      if (!empty(in_unused)) {
        edges.push_back({i, in_unused.back()});
        in_unused.pop_back();
      } else
        edges.push_back({i, num_sccs - 1});
    }

  for (int u : in_unused) edges.push_back({0, u});

  vi to_node(num_sccs);
  for (int i = 0; i < n; i++) to_node[scc_id[i]] = i;
  for (auto& [u, v] : edges) u = to_node[u], v = to_node[v];

  return edges;
}
