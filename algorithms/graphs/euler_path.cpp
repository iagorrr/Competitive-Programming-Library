// Directed Edges
vector<int> euler_cycle_directed(vector<vector<int>> &g, int u)
{
  vector<int> res;
 
  stack<int> st;
  st.push(u);
  while (!st.empty())
  {
    auto cur = st.top();
    if (g[cur].empty()) {
      res.push_back(cur);
      st.pop();
    } else {
      auto next = g[cur].back();
      st.push(next);
 
      g[cur].pop_back();
    }
  }
 
  for (auto &x : g)
    if (!x.empty())
      return {};
 
  return res;
}
 
// Directed Edges
vector<int> euler_path_directed(vector<vector<int>> &g, int first)
{
  {
    int n = (int)g.size();
    vector<int> in(n), out(n);
    for (int i = 0; i < n; i++)
      for (auto x : g[i])
        in[x]++, out[i]++;

    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++)
      if (in[i] == out[i]) c++;
      else if (in[i] - out[i] == 1) b++;
      else if (in[i] - out[i] == -1) a++;

    if (c != n-2 or a != 1 or b != 1) return {};
  }

  auto res = euler_cycle_directed(g, first);
  if (res.empty()) return res;
 
  reverse(all(res));
  return res;
}

// Undirected Edges
vector<int> euler_cycle_undirected(vector<vector<int>> &g, int u)
{
  vector<int> res;
  multiset<pair<int, int>> vis;

  stack<int> st;
  st.push(u);
  while (!st.empty())
  {
    auto cur = st.top();

    while (!g[cur].empty()) {
      auto it = vis.find(make_pair(cur, g[cur].back()));
      if (it == vis.end()) break;
      g[cur].pop_back();
      vis.erase(it);
    }

    if (g[cur].empty()) {
      res.push_back(cur);
      st.pop();
    } else {
      auto next = g[cur].back();
      st.push(next);

      vis.emplace(next, cur);
      g[cur].pop_back();
    }
  }
 
  for (auto &x : g)
    if (!x.empty())
      return {};
 
  return res;
}

// Undirected edges
vector<int> euler_path_undirected(vector<vector<int>> &g, int first)
{
  int n = (int)g.size();
  int v1 = -1, v2 = -1;
  {
    bool bad = false;
    for (int i = 0; i < n; i++)
      if (g[i].size() & 1)
      {
        if (v1 == -1) v1 = i;
        else if (v2 == -1) v2 = i;
        else bad = true;
      }
 
    if (bad or (v1 != -1 and v2 == -1)) return {};
  }

  if (v2 != -1)
  {
    // insert cycle
    g[v1].push_back(v2);
    g[v2].push_back(v1);
  }
 
  auto res = euler_cycle_undirected(g, first);
  if (res.empty()) return res;
 
  if (v1 != -1)
  {
    for (int i = 0; i + 1 < (int)res.size(); i++)
    {
      if ((res[i] == v1 and res[i+1] == v2) ||
          (res[i] == v2 and res[i+1] == v1)) {
        vector<int> res2;
        for (int j = i + 1; j < (int)res.size(); j++)
          res2.push_back(res[j]);
        for (int j = 1; j <= i; j++)
          res2.push_back(res[j]);
        res = res2;
        break;
      }
    }
  }
 
  reverse(all(res));
  return res;
}
