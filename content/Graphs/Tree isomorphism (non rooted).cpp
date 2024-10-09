/*8<
  @Title:

    Tree Isomorphism (not rooted)

  @Description:

    Two trees are considered \textbf{isomorphic}
    if the hash given by $thash()$ is the same.

  @Time:

    $O(V \cdot \log{V})$
>8*/

map<vi, int> mphash;

struct Tree {
  int n;
  vi2d g;
  vi sz, cs;

  Tree(int n_) : n(n_), g(n), sz(n) {}

  void add_edge(int u, int v) {
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }

  void dfs_centroid(int v, int p) {
    sz[v] = 1;
    bool cent = true;
    for (int u : g[v])
      if (u != p) {
        dfs_centroid(u, v);
        sz[v] += sz[u];
        cent &= not(sz[u] > n / 2);
      }
    if (cent and n - sz[v] <= n / 2) cs.push_back(v);
  }

  int fhash(int v, int p) {
    vi h;
    for (int u : g[v])
      if (u != p) h.push_back(fhash(u, v));
    sort(all(h));
    if (!mphash.count(h)) mphash[h] = mphash.size();
    return mphash[h];
  }

  ll thash() {
    cs.clear();
    dfs_centroid(0, -1);
    if (cs.size() == 1) return fhash(cs[0], -1);
    ll h1 = fhash(cs[0], cs[1]), h2 = fhash(cs[1], cs[0]);
    return (min(h1, h2) << 30ll) + max(h1, h2);
  }
};
