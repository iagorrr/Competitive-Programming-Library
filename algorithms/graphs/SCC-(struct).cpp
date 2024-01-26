struct SCC {
  int N, totscc;
  vi2d g, tg;
  vi todo, comp;
  vector<set<ll>> gscc;
  vc vis;
  SCC(int _N)
    : N(_N),
      totscc(0),
      g(_N),
      tg(_N),
      comp(_N, -1),
      gscc(_N),
      vis(_N) {}

  void add_edge(int x, int y) { g[x].eb(y), tg[y].eb(x); }

  void dfs(int x) {
    vis[x] = 1;
    for (auto y : g[x])
      if (!vis[y]) dfs(y);
    todo.pb(x);
  }

  void dfs2(ll x) {
    comp[x] = totscc;
    for (auto y : tg[x])
      if (comp[y] == -1) dfs2(y);
  }

  void build() {
    for (int i = 0; i < N; ++i)
      if (!vis[i]) dfs(i);

    reverse(all(todo));
    for (auto &x : todo)
      if (comp[x] == -1) {
        dfs2(x);
        totscc++;
      }

    for (int i = 0; i < N; ++i)
      for (auto j : g[i])
        if (comp[i] != comp[j])
          gscc[comp[i]].insert(comp[j]);
  }
};
