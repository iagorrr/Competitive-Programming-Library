/*8<
  @Title:

    Lowest Common Ancestor (Binary Lifting)

  @Description:

    Given a directed tree, finds the LCA between
    two nodes using binary lifting, and answer a
    few queries with it.

  @Usage:

    \begin{compactitem}
      \item lca: returns the LCA between the two
      given nodes
      \item on\_path: fids if $c$ is in the
      path from $a$ to $b$
  \end{compactitem}

  @Time:

    build $O(N \cdot MAXLOG2)$, all queries
$O(MAXLOG2)$ >8*/
struct LCA {
  int n;
  const int maxlog;
  vector<vector<int>> up;
  vector<int> depth;

  LCA(const vector<vector<int>> &tree)
      : n(tree.size()),
        maxlog(ceil(log2(n))),
        up(n, vector<int>(maxlog + 1)),
        depth(n, -1) {
    for (int i = 0; i < n; i++) {
      if (depth[i] == -1) {
        depth[i] = 0;
        dfs(i, -1, tree);
      }
    }
  }

  void dfs(int u, int p,
           const vector<vector<int>> &tree) {
    if (p != -1) {
      depth[u] = depth[p] + 1;
      up[u][0] = p;
      for (int i = 1; i <= maxlog; i++) {
        up[u][i] = up[up[u][i - 1]][i - 1];
      }
    }
    for (int v : tree[u]) {
      if (v == p) continue;
      dfs(v, u, tree);
    }
  }

  int kth_jump(int u, int k) {
    for (int i = maxlog; i >= 0; i--) {
      if ((1 << i) & k) {
        u = up[u][i];
      }
    }
    return u;
  }

  int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    u = kth_jump(u, diff);
    if (u == v) return u;
    for (int i = maxlog; i >= 0; i--) {
      if (up[u][i] != up[v][i]) {
        u = up[u][i];
        v = up[v][i];
      }
    }
    return up[u][0];
  }

  bool on_path(int u, int v, int s) {
    int uv = lca(u, v), us = lca(u, s),
        vs = lca(v, s);
    return (uv == s or (us == uv and vs == s) or
            (vs == uv and us == s));
  }

  int dist(int u, int v) {
    return depth[u] + depth[v] -
           2 * depth[lca(u, v)];
  }
};
