#pragma once
#include "../Contest/template.cpp"
#include "./Lowest common ancestor (sparse table).cpp"

struct VTree {
  int n;
  LCA lca;
  VTree(const Graph& g, int root = 0) : n(len(g)), lca(g, root) {}
  pair<vector<tuple<ll, int, int>>, int> vtree(vector<int> vs) {
    sort(vs.begin(), vs.end(),
         [&](int u, int v) { return lca.pos[u] < lca.pos[v]; });
    for (int i = 0, n = size(vs); i + 1 < n; i++) {
      vs.eb(lca.lca(vs[i], vs[i + 1]));
    }
    sort(vs.begin(), vs.end(),
         [&](int u, int v) { return lca.pos[u] < lca.pos[v]; });
    vs.erase(unique(all(vs)), vs.end());
    vi st{vs.front()};
    vector<tuple<ll, int, int>> ret;
    for (int i = 1; i < len(vs); i++) {
      int v = vs[i];
      while (len(st) >= 2 && lca.lca(v, st.back()) != st.back()) {
        int a = end(st)[-2];
        int b = st.back();
        ll c = lca.dist(a, b);
        ret.eb(c, a, b);
        st.pop_back();
      }
      st.pb(v);
    }
    while (len(st) >= 2) {
      int a = end(st)[-2];
      int b = st.back();
      ll c = lca.dist(a, b);
      ret.eb(c, a, b);
      st.pop_back();
    }
    return {ret, st.back()};
  }
};
