template <typename T = ll>
struct SegTree {
  int N;
  vector<T> st, lazy;

  SegTree(const vector<T> &xs) : N(len(xs)), st(4 * N, 0), lazy(4 * N, 0) {
    for (int i = 0; i < len(xs); ++i) update(i, i, xs[i]);
  }

  SegTree(int n) : N(n), st(4 * N, 0), lazy(4 * N, 0) {}

  void update(int l, int r, ll value) { update(1, 0, N - 1, l, r, value); }

  T RSQ(int l, int r) { return RSQ(1, 0, N - 1, l, r); }

  void update(int node, int nl, int nr, int ql, int qr, ll v) {
    propagation(node, nl, nr);

    if (ql > nr or qr < nl) return;

    if (ql <= nl and nr <= qr) {
      st[node] += (nr - nl + 1) * v;

      if (nl < nr) {
        lazy[left(node)] += v;
        lazy[right(node)] += v;
      }

      return;
    }

    update(left(node), nl, mid(nl, nr), ql, qr, v);
    update(right(node), mid(nl, nr) + 1, nr, ql, qr, v);

    st[node] = st[left(node)] + st[right(node)];
  }

  T RSQ(int node, int nl, int nr, int ql, int qr) {
    propagation(node, nl, nr);

    if (ql > nr or qr < nl) return 0;

    if (ql <= nl and nr <= qr) return st[node];

    T x = RSQ(left(node), nl, mid(nl, nr), ql, qr);
    T y = RSQ(right(node), mid(nl, nr) + 1, nr, ql, qr);

    return x + y;
  }

  void propagation(int node, int nl, int nr) {
    if (lazy[node]) {
      st[node] += (nr - nl + 1) * lazy[node];

      if (nl < nr) {
        lazy[left(node)] += lazy[node];
        lazy[right(node)] += lazy[node];
      }

      lazy[node] = 0;
    }
  }

  int left(int p) { return p << 1; }
  int right(int p) { return (p << 1) + 1; }
  int mid(int l, int r) { return (r - l) / 2 + l; }
};
