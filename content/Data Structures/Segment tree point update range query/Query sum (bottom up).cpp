struct Node {
  ll value;
  Node() : value(0){};  // Neutral element
  Node(ll v) : value(v){};
};

inline Node combine(const Node &nl,
                    const Node &nr) {
  Node m;
  m.value = nl.value + nr.value;
  return m;
}

struct SegTree {
  int n;
  vector<Node> st;
  SegTree(int _n) : n(_n), st(n << 1) {}

  void assign(int p, const Node &k) {
    for (st[p += n] = k; p >>= 1;)
      st[p] = combine(st[p << 1], st[p << 1 | 1]);
  }

  Node query(int l, int r) {
    Node ansl = Node(), ansr = Node();
    for (l += n, r += n + 1; l < r;
         l >>= 1, r >>= 1) {
      if (l & 1) ansl = combine(ansl, st[l++]);
      if (r & 1) ansr = combine(st[--r], ansr);
    }
    return combine(ansl, ansr);
  }
};
