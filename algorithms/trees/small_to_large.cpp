struct SmallToLarge {
  int n;
  vi2d tree, vis_childs;
  vi sizes, values, ans;
  set<int> cnt;

  SmallToLarge(vi2d &g, vi &v)
    : tree(g), vis_childs(len(g)), sizes(len(g)), values(v), ans(len(g)) {
    get_size(0);
    dfs(0);
  }

  inline void add_value(int u) { cnt.insert(values[u]); }

  inline void remove_value(int u) { cnt.erase(values[u]); }

  inline void update_ans(int u) { ans[u] = len(cnt); }

  void dfs(int u, int p = -1, bool keep = true) {
    int mx = -1;
    for (auto x : tree[u]) {
      if (x == p) continue;

      if (mx == -1 or sizes[mx] < sizes[x]) mx = x;
    }

    for (auto x : tree[u]) {
      if (x != p and x != mx) dfs(x, u, false);
    }

    if (mx != -1) {
      dfs(mx, u, true);
      swap(vis_childs[u], vis_childs[mx]);
    }

    vis_childs[u].push_back(u);
    add_value(u);

    for (auto x : tree[u]) {
      if (x != p and x != mx) {
        for (auto y : vis_childs[x]) {
          add_value(y);
          vis_childs[u].push_back(y);
        }
      }
    }

    update_ans(u);

    if (!keep) {
      for (auto x : vis_childs[u]) remove_value(x);
    }
  }

  void get_size(int u, int p = -1) {
    sizes[u] = 1;
    for (auto x : tree[u])
      if (x != p) {
        get_size(x, u);
        sizes[u] += sizes[x];
      }
  }
};
