struct ArrayCycle {
  vector<vector<int>> paths;
  vector<int> path_num, pos;
  vector<char> is_cycle;

  ArrayCycle(const vector<int> &v) : path_num(v.size()), pos(v.size()) {
    paths.reserve(v.size());
    is_cycle.reserve(v.size());

    vector<char> vis(v.size());
    for (auto i : topological_order(v)) {
      if (vis[i]) continue;

      vector<int> path;
      int cur;
      for (cur = i; not vis[cur]; cur = v[cur]) {
        path.push_back(cur);
        vis[cur] = 1;
      }

      {
        int cycle_start = 0;
        for (; cycle_start < (int)path.size() and path[cycle_start] != cur; cycle_start++);

        if (cycle_start > 0) {
          paths.emplace_back();
          for (int j = 0; j < cycle_start; j++) {
            paths.back().push_back(path[j]);
            pos[path[j]] = j;
            path_num[path[j]] = (int)paths.size() - 1;
          }
          paths.back().push_back(cur);
          is_cycle.push_back(false);
        }

        if (cycle_start < (int)path.size()) {
          paths.emplace_back();
          for (int j = cycle_start; j < (int)path.size(); j++) {
            paths.back().push_back(path[j]);
            pos[path[j]] = j - cycle_start;
            path_num[path[j]] = (int)paths.size() - 1;
          }
          is_cycle.push_back(true);
        }
      }
    }
  }

  const vector<int> &path(int cur) const {
    return paths[path_num[cur]];
  }

  int kth_pos(int cur, ll k) const {
    while (not is_cycle[path_num[cur]]) {
      auto &p = path(cur);
      int remain = (int)p.size() - pos[cur] - 1;
      if (k <= remain) return p[pos[cur] + k];
      cur = p.back();
      k -= remain;
    }

    auto &p = path(cur);
    return p[(pos[cur]+k)%p.size()];
  }

  // {element, number_of_moves}
  pair<int, int> go_to_cycle(int cur) const {
    int moves = 0;
    while (not is_cycle[path_num[cur]]) {
      auto &p = path(cur);
      moves += (int)p.size() - pos[cur] - 1;
      cur = p.back();
    }
    return {cur, moves};
  }

  void topological_order(const vector<int> &g, vector<char> &vis, vector<int> &order, int u)
  {
    vis[u] = true;
    if (not vis[g[u]])
      topological_order(g, vis, order, g[u]);
    order.push_back(u);
  }

  vector<int> topological_order(const vector<int> &g)
  {
    vector<char> vis(g.size(), false);
    vector<int> order;
    for (auto i = 0; i < (int)g.size(); i++)
      if (not vis[i])
        topological_order(g, vis, order, i);
    reverse(order.begin(), order.end());
    return order;
  }
};
