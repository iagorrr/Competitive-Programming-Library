template <typename T = ll>
struct SegTree {
  int n;
  T nu, nq;
  vector<T> st;
  SegTree(const vector<T> &v) : n(len(v)), nu(0), nq(0), st(n * 4 + 1, nu) {
    for (int i = 0; i < n; ++i) update(i, v[i]);
  }
  void update(int p, T v) { update(1, 0, n - 1, p, v); }
  T query(int l, int r) { return query(1, 0, n - 1, l, r); }

  void update(int node, int nl, int nr, int p, T v) {
    if (p < nl or p > nr) return;

    if (nl == nr) {
      st[node] = v;
      return;
    }

    update(left(node), nl, mid(nl, nr), p, v);
    update(right(node), mid(nl, nr) + 1, nr, p, v);

    st[node] = st[left(node)] ^ st[right(node)];
  }

  T query(int node, int nl, int nr, int ql, int qr) {
    if (ql <= nl and qr >= nr) return st[node];
    if (nl > qr or nr < ql) return nq;
    if (nl == nr) return st[node];

    return query(left(node), nl, mid(nl, nr), ql, qr) ^
           query(right(node), mid(nl, nr) + 1, nr, ql, qr);
  }

  int left(int p) { return p << 1; }
  int right(int p) { return (p << 1) + 1; }
  int mid(int l, int r) { return (r - l) / 2 + l; }
};
