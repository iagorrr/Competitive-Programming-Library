/*8<
  @Title:
    Kruskal

  @Description:

    Find the minimum spanning tree of a graph.

  @Time:

    $O(E \log E)$
>8*/
#include "./../Data Structures/DSU.cpp"
vector<tuple<ll, int, int>> kruskal(int n, vector<tuple<ll, int, int>> &edges) {
  DSU dsu(n);
  vector<tuple<ll, int, int>> ans;

  sort(all(edges));
  for (auto [a, b, c] : edges) {
    if (dsu.same_set(b, c)) continue;

    ans.emplace_back(a, b, c);
    dsu.union_set(b, c);
  }

  return ans;
}
