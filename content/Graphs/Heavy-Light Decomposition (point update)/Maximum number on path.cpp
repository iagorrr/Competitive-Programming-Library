struct Node {
  ll value;
  Node()
      : value(numeric_limits<ll>::min()){};  // Neutral
                                             // element
  Node(ll v) : value(v){};
};

Node combine(Node l, Node r) {
  Node m;
  m.value = max(l.value, r.value);
  return m;
}

template <typename T = Node, auto F = combine>
struct SegTree {
  int n;
  vector<T> st;
  SegTree(int _n) : n(_n), st(n << 1) {}

  void set(int p, const T &k) {
    for (st[p += n] = k; p >>= 1;) st[p] = F(st[p << 1], st[p << 1 | 1]);
  }

  T query(int l, int r) {
    T ansl, ansr;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) ansl = F(ansl, st[l++]);
      if (r & 1) ansr = F(st[--r], ansr);
    }
    return F(ansl, ansr);
  }
};

template <typename SegT = Node, auto SegOp = combine>
struct HeavyLightDecomposition {
  int n;
  vi ps, ds, sz, heavy, head, pos;
  SegTree<SegT, SegOp> seg;

  HeavyLightDecomposition(const vi2d &g, const vector<SegT> &v, int root = 0)
      : n(len(g)), seg(n) {
    ps = ds = sz = heavy = head = pos = vi(n, -1);

    auto dfs = [&](auto &&self, int u) -> void {
      sz[u] = 1;
      int mx = 0;
      for (auto x : g[u])
        if (x != ps[u]) {
          ps[x] = u;
          ds[x] = ds[u] + 1;
          self(self, x);
          sz[u] += sz[x];
          if (sz[x] > mx) mx = sz[x], heavy[u] = x;
        }
    };

    dfs(dfs, root);

    for (int i = 0, cur = 0; i < n; i++) {
      if (ps[i] == -1 or heavy[ps[i]] != i)
        for (int j = i; j != -1; j = heavy[j]) {
          head[j] = i;
          pos[j] = cur++;
        }
    }

    rep(i, 0, n) seg.set(pos[i], v[i]);
  }

  vector<pii> disjoint_ranges(int u, int v) {
    vector<pii> ret;
    for (; head[u] != head[v]; v = ps[head[v]]) {
      if (ds[head[u]] > ds[head[v]]) swap(u, v);

      ret.eb(pos[head[v]], pos[v]);
    }
    if (ds[u] > ds[v]) swap(u, v);
    ret.eb(pos[u], pos[v]);
    return ret;
  }

  SegT query_path(int u, int v) {
    SegT res;
    for (auto [l, r] : disjoint_ranges(u, v)) {
      res = SegOp(res, seg.query(l, r));
    }
    return res;
  }

  SegT query_subtree(int u) const {
    return seg.query(pos[u], pos[u] + sz[u] - 1);
  }

  void set(int u, SegT x) { seg.set(pos[u], x); }
};
