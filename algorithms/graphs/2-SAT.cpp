struct SAT {
  int n;
  vi2d g, tg;
  vi vis;
  vi order, comp;
  vc assignment;
  bool solvable;
  int qtdcomp;

  SAT(int _n)
    : n(2 * _n),
      g(n),
      tg(n),
      vis(n),
      comp(n, -1),
      assignment(n / 2) {}

  void dfs1(int u) {
    vis[u] = 1;
    for (auto v : g[u]) {
      if (!vis[v]) {
        dfs1(v);
      }
    }
    order.emplace_back(u);
  }

  void dfs2(int u) {
    comp[u] = qtdcomp;
    for (auto v : tg[u]) {
      if (comp[v] == -1) {
        dfs2(v);
      }
    }
  }

  bool solve2sat() {
    for (int i = 0; i < n; i++) {
      if (!vis[i]) dfs1(i);
    }

    reverse(all(order));
    qtdcomp = 0;
    for (auto u : order) {
      if (comp[u] == -1) {
        dfs2(u);
        qtdcomp++;
      }
    }

    assignment.assign(n / 2, false);
    for (int i = 0; i < n; i += 2) {
      if (comp[i] == comp[i + 1]) {
        solvable = false;
        return false;
      }

      assignment[i / 2] = comp[i] < comp[i + 1];
    }

    solvable = 1;
    return solvable;
  }

  void add_dis(int a, bool va, int b, bool vb) {
    va = !va, vb = !vb;
    a = (2 * a) ^ va, b = (2 * b) ^ vb;
    int nota = a ^ 1, notb = b ^ 1;
    g[nota].emplace_back(b), g[notb].emplace_back(a),
      tg[b].emplace_back(nota), tg[a].emplace_back(notb);
  }

  void add_impl(int a, bool va, int b, int vb) {
    add_dis(a, !va, b, vb);
  }
};
