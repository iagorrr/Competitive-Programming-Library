void tree_flatten(const vector<vector<int>> &g, int u, int p, vector<int> &pre, vector<int> &pos, int &idx) {
  ++idx;
  pre.push_back(u);
  for (auto x : g[u])
    if (x != p)
      tree_flatten(g, x, u, pre, pos, idx);
  pos[u] = idx;
}

pair<vector<int>, vector<int>> tree_flatten(const vector<vector<int>> &g, int root=0) {
  vector<int> first(g.size()), last(g.size()), pre;
  int timer = -1;
  tree_flatten(g, root, -1, pre, last, timer);
  for (int i = 0; i < (int)g.size(); i++)
    first[pre[i]] = i;
  return {first, last};
}
