map<vi, int> hasher;
int hs = 0;
struct RootedTreeIso {
  int n;
  vi2d adj;
  vi hashes;
  RootedTreeIso(int _n) : n(_n), adj(_n), hashes(_n, -1){};

  void add_edge(int u, int v) {
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  int hash(int u, int p = -1) {
    if (hashes[u] != -1) return hashes[u];

    vi children;
    for (auto v : adj[u])
      if (v != p) children.emplace_back(hash(v, u));

    sort(all(children));
    if (!hasher.count(children)) hasher[children] = hs++;

    return hashes[u] = hasher[children];
  }
};
