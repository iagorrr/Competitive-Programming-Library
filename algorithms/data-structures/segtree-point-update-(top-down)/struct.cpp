const ll E = 1'000'000'000'000;

struct Node {
  ll value;

  Node() : value(E) {} // Neutral element
};

Node combine(const Node &vl, const Node &vr, int nl, int nr,
             int ql, int qr);

struct SegTree {
  int n;
  vector<Node> st;
  SegTree(int n) : n(n), st(n << 2) {}

  void assign(int p, const Node &v) {
    assign(1, 0, n - 1, p, v);
  }
  void assign(int node, int l, int r, int p,
              const Node &v) {
    if (l == r) {
      st[node] = v;
      return;
    }

    int m = midpoint(l, r);
    if (p <= m)
      assign(node << 1, l, m, p, v);
    else
      assign(node << 1 | 1, m + 1, r, p, v);

    st[node] =
      combine(st[node << 1], st[node << 1 | 1], l, r, l, r);
  }

  inline Node query(int l, int r) {
    return query(1, 0, n - 1, l, r);
  }

  inline Node query(int node, int nl, int nr, int l,
                    int r) const {
    if (r < nl or nr < l) return Node();
    if (l <= nl and nr <= r) return st[node];

    int m = midpoint(nl, nr);
    auto a = query(node << 1, nl, m, l, r);
    auto b = query(node << 1 | 1, m + 1, nr, l, r);

    return combine(a, b, nl, nr, l, r);
  }
};
