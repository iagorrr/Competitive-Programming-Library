struct BinaryLifting {
  vector<int> far, level, parent;

  BinaryLifting(const vector<vector<int>> &g, int root=0) : far(g.size(), -1), level(g.size()), parent(g.size()) {
    level[root] = 1;
    vector<int> q{root};
    q.reserve(g.size());
    for (int u = 0; u < (int)q.size(); u++) {
      for (auto x : g[u]) if (x != parent[u]) {
        parent[x] = u;
        level[x] = level[u] + 1;

        int p1 = u;
        int p2 = far[u];

        if (p2 > -1 and far[p2] > -1 and level[p1] - level[p2] == level[p2] - level[far[p2]])
          far[x] = far[p2];
        else
          far[x] = p1;

        q.push_back(x);
      }
    }
  }

  int kth_parent(int node, int k) const
  {
    while (node >= 0 and k > 0)
    {
      if (far[node] > -1 and level[node] - k <= level[far[node]])
      {
        k -= level[node] - level[far[node]];
        node = far[node];
      }
      else
      {
        k--;
        node = parent[node];
      }
    }

    return node;
  }

  int lca(int u, int v) const {
    if (level[u] < level[v]) swap(u, v);

    while (level[v] < level[u]) {
      if (far[u] > -1 and level[v] <= level[far[u]])
        u = far[u];
      else
        u = parent[u];
    }

    if (u == v) return u;

    while (parent[u] != parent[v]) {
      if (far[u] > -1 and far[v] > -1 and far[u] != far[v]) {
        u = far[u];
        v = far[v];
      } else {
        u = parent[u];
        v = parent[v];
      }
    }

    return parent[u];
  }
};
