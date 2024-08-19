const ll MOD = 1'000'000'009;
const ll P = 31;
const int MAXN = 2'000'000;

ll pows[MAXN + 1];
void computepows() {
  pows[0] = 1;
  for (int i = 1; i <= MAXN; i++) {
    pows[i] = (pows[i - 1] * P) % MOD;
  }
}

struct Node {
  ll hash;
  Node() : hash(-1){};  // Neutral element
  Node(ll v) : hash(v){};
};

inline Node combine(Node &vl, Node &vr, int nl,
                    int nr, int ql, int qr) {
  if (vl.hash == -1) return vr;
  if (vr.hash == -1) return vl;
  Node vm;

  int nm = midpoint(nl, nr);
  int lsize = min(nm, qr) - max(nl, ql) + 1;
  vm.hash = (vl.hash +
             ((vr.hash * pows[lsize]) % MOD)) %
            MOD;
  return vm;
}

template <typename T = Node, auto F = combine>
struct SegTree {
  int n;
  vector<T> st;
  SegTree(int n) : n(n), st(n << 2) {}

  void assign(int p, const T &v) {
    assign(1, 0, n - 1, p, v);
  }
  void assign(int node, int l, int r, int p,
              const T &v) {
    if (l == r) {
      st[node] = v;
      return;
    }

    int m = midpoint(l, r);
    if (p <= m)
      assign(node << 1, l, m, p, v);
    else
      assign(node << 1 | 1, m + 1, r, p, v);

    st[node] = F(st[node << 1], st[node << 1 | 1],
                 l, r, l, r);
  }

  inline T query(int l, int r) {
    return query(1, 0, n - 1, l, r);
  }

  inline T query(int node, int nl, int nr, int l,
                 int r) const {
    if (r < nl or nr < l) return T();
    if (l <= nl and nr <= r) return st[node];

    int m = midpoint(nl, nr);
    auto a = query(node << 1, nl, m, l, r);
    auto b =
        query(node << 1 | 1, m + 1, nr, l, r);

    return F(a, b, nl, nr, l, r);
  }
};
