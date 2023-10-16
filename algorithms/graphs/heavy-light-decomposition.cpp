struct HeavyLightDecomposition {
  vector<int> parent, depth, size, heavy, head, pos;

  using SegT = int;
  static SegT op(SegT a, SegT b) { return max(a, b); }
  SegTree<SegT, op> seg;

  HeavyLightDecomposition(const vector<vector<int>> &g, const vector<int> &v, int root=0) : parent(g.size()), depth(g.size()), size(g.size()), heavy(g.size(), -1), head(g.size()), pos(g.size()), seg((int)g.size()) {
    dfs(g, root);
    int cur_pos = 0;
    decompose(g, root, root, cur_pos);

    for (int i = 0; i < (int)g.size(); i++) {
      seg.set(pos[i], v[i]);
    }
  }

  SegT query_path(int a, int b) const {
    int res = 0;
    for (; head[a] != head[b]; b = parent[head[b]]) {
      if (depth[head[a]] > depth[head[b]])
        swap(a, b);
      res = op(res, seg.query(pos[head[b]], pos[b]));
    }
    if (depth[a] > depth[b])
      swap(a, b);
    return op(res, seg.query(pos[a], pos[b]));
  }

  SegT query_subtree(int a) const {
    return seg.query(pos[a], pos[a]+size[a]-1);
  }

  void set(int a, int x) {
    seg.set(pos[a], x);
  }

private:
  void dfs(const vector<vector<int>> &g, int u) {
    size[u] = 1;
    int mx_child_size = 0;
    for (auto x : g[u]) if (x != parent[u]) {
      parent[x] = u;
      depth[x] = depth[u] + 1;
      dfs(g, x);
      size[u] += size[x];
      if (size[x] > mx_child_size)
        mx_child_size = size[x], heavy[u] = x;
    }
  }

  void decompose(const vector<vector<int>> &g, int u, int h, int &cur_pos) {
    head[u] = h;
    pos[u] = cur_pos++;
    if (heavy[u] != -1)
      decompose(g, heavy[u], h, cur_pos);

    for (auto x : g[u]) if (x != parent[u] and x != heavy[u]) {
      decompose(g, x, x, cur_pos);
    }
  }
};
