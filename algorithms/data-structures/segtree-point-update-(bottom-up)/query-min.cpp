using ll = long long;

const ll oo = numeric_limits<ll>::max();

struct Node {
  ll value;
  Node() : value(oo){};  // Neutral element
  Node(ll v) : value(v){};
};

Node combine(Node &l, Node &r) {
  Node m;
  m.value = min(l.value, r.value);
  return m;
}

template <typename T=Node, auto F=combine>
struct SegTree {
  int n;
  vector<T> st;
  SegTree(int _n) : n(_n), st(n << 1) {}

  void assign(int p, const T& k) {
    for (st[p += n] = k; p >>= 1;)
      st[p] = F(st[p << 1], st[p << 1 | 1]);
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
