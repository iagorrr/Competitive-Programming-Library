template <typename T = ll>
struct SegTree {
  int N;
  T nu, nq;
  vector<T> st, lazy;
  SegTree(const vector<T> &xs)
    : N(len(xs)),
      nu(numeric_limits<T>::min()),
      nq(numeric_limits<T>::min()),
      st(4 * N + 1, nu),
      lazy(4 * N + 1, nu) {
    for (int i = 0; i < len(xs); ++i) update(i, i, xs[i]);
  }

  void update(int l, int r, T value) {
    update(1, 0, N - 1, l, r, value);
  }

  T query(int l, int r) { return query(1, 0, N - 1, l, r); }

  void update(int node, int nl, int nr, int ql, int qr,
              T v) {
    propagation(node, nl, nr);

    if (ql > nr or qr < nl) return;

    st[node] = max(st[node], v);
    if (ql <= nl and nr <= qr) {
      if (nl < nr) {
        lazy[left(node)] = max(lazy[left(node)], v);
        lazy[right(node)] = max(lazy[right(node)], v);
      }
      return;
    }
    update(left(node), nl, mid(nl, nr), ql, qr, v);
    update(right(node), mid(nl, nr) + 1, nr, ql, qr, v);

    st[node] = max(st[left(node)], st[right(node)]);
  }

  T query(int node, int nl, int nr, int ql, int qr) {
    propagation(node, nl, nr);

    if (ql > nr or qr < nl) return nq;

    if (ql <= nl and nr <= qr) return st[node];

    T x = query(left(node), nl, mid(nl, nr), ql, qr);
    T y = query(right(node), mid(nl, nr) + 1, nr, ql, qr);

    return max(x, y);
  }

  void propagation(int node, int nl, int nr) {
    if (lazy[node] != nu) {
      st[node] = max(st[node], lazy[node]);

      if (nl < nr) {
        lazy[left(node)] =
          max(lazy[left(node)], lazy[node]);
        lazy[right(node)] =
          max(lazy[right(node)], lazy[node]);
      }

      lazy[node] = nu;
    }
  }

  int left(int p) { return p << 1; }
  int right(int p) { return (p << 1) + 1; }
  int mid(int l, int r) { return (r - l) / 2 + l; }
};
int main() {
  int n;
  cin >> n;
  vector<array<int, 3>> xs(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> xs[i][j];
    }
  }
  vi aux(n, 0);
  SegTree<int> st(aux);
  for (int i = 0; i < n; ++i) {
    int a = min(i + xs[i][1], n);
    int b = min(i + xs[i][2], n);
    st.update(i, i, st.query(i, i) + xs[i][0]);
    int cur = st.query(i, i);
    st.update(a, b, cur);
  }

  cout << st.query(0, n) << '\n';
}
