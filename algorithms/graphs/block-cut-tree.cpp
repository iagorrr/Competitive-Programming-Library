struct block_cut_tree {
  int n;
  vector<int> id, is_cutpoint, tin, low, stk;
  vector<vector<int>> comps, tree;
  block_cut_tree(vector<vector<int>> &g)
    : n(g.size()), id(n), is_cutpoint(n), tin(n), low(n) {
    // build comps
    for (int i = 0; i < n; i++) {
      if (!tin[i]) {
        int timer = 0;
        dfs(i, -1, timer, g);
      }
    }

    int node_id = 0;
    for (int u = 0; u < n; u++) {
      if (is_cutpoint[u]) {
        id[u] = node_id++;
        tree.push_back({});
      }
    }

    for (auto &comp : comps) {
      int node = node_id++;
      tree.push_back({});
      for (int u : comp) {
        if (!is_cutpoint[u]) {
          id[u] = node;
        } else {
          tree[node].emplace_back(id[u]);
          tree[id[u]].emplace_back(node);
        }
      }
    }
  }

  void dfs(int u, int p, int &timer,
           vector<vector<int>> &g) {
    tin[u] = low[u] = ++timer;
    stk.emplace_back(u);

    for (auto v : g[u]) {
      if (v == p) continue;
      if (!tin[v]) {
        dfs(v, u, timer, g);
        low[u] = min(low[u], low[v]);
        if (low[v] >= tin[u]) {
          is_cutpoint[u] = (tin[u] > 1 or tin[v] > 2);
          comps.push_back({u});
          while (comps.back().back() != v) {
            comps.back().emplace_back(stk.back());
            stk.pop_back();
          }
        }
      } else
        low[u] = min(low[u], tin[v]);
    }
  }
};
