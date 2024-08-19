/*8<
  @Title:
    Minimum Vertex Cover (already divided)

  @Description:

    Given a bipartite graph $g$ with $n$ vertices
    at left and $m$ vertices at right, where
    $g[i]$ are the possible right side matches of
    vertex $i$ from left side, find a minimum
    vertex cover. The size is the same as the
    size of the maximum matching, and the
    complement is a maximum independent set.
>8*/

vector<int> min_vertex_cover(
    vector<vector<int>> &g, int n, int m) {
  vector<int> match(m, -1), vis;

  auto find = [&](auto &&self, int j) -> bool {
    if (match[j] == -1) return 1;
    vis[j] = 1;
    int di = match[j];
    for (int e : g[di])
      if (!vis[e] and self(self, e)) {
        match[e] = di;
        return 1;
      }
    return 0;
  };

  for (int i = 0; i < (int)g.size(); i++) {
    vis.assign(match.size(), 0);
    for (int j : g[i]) {
      if (find(find, j)) {
        match[j] = i;
        break;
      }
    }
  }

  int res =
      (int)match.size() -
      (int)count(match.begin(), match.end(), -1);

  vector<char> lfound(n, true), seen(m);
  for (int it : match)
    if (it != -1) lfound[it] = false;

  vector<int> q, cover;
  for (int i = 0; i < n; i++)
    if (lfound[i]) q.push_back(i);

  while (!q.empty()) {
    int i = q.back();
    q.pop_back();
    lfound[i] = 1;
    for (int e : g[i])
      if (!seen[e] and match[e] != -1) {
        seen[e] = true;
        q.push_back(match[e]);
      }
  }

  for (int i = 0; i < n; i++)
    if (!lfound[i]) cover.push_back(i);

  for (int i = 0; i < m; i++)
    if (seen[i]) cover.push_back(n + i);

  assert((int)size(cover) == res);

  return cover;
}
