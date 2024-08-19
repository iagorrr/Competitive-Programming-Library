
/*8<
  @Title:
    Tree Isomorphism (rooted)

  @Description:

    Given a rooted tree find the hash of each
    subtree, if two roots of two distinct trees
    have the same hash they are considered
    isomorphic

  @Time:

    hash first time in $O(\log{N_v} \cdot N_v)$
    where $(N_v)$ is the of the subtree of $v$
>8*/

map<vi, int> hasher;
int hs = 0;
struct RootedTreeIso {
  int n;
  vi2d adj;
  vi hashes;
  RootedTreeIso(int _n)
      : n(_n), adj(_n), hashes(_n, -1){};

  void add_edge(int u, int v) {
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  int hash(int u, int p = -1) {
    if (hashes[u] != -1) return hashes[u];

    vi children;
    for (auto v : adj[u])
      if (v != p)
        children.emplace_back(hash(v, u));

    sort(all(children));
    if (!hasher.count(children))
      hasher[children] = hs++;

    return hashes[u] = hasher[children];
  }
};
