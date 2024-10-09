/*8<

  @Problems:
    https://codeforces.com/contest/1547/problem/F

>8*/

using ll = long long;

struct Node {
  ll value;
  bool undef;
  Node() : value(1), undef(1){};  // Neutral element
  Node(ll v) : value(v), undef(0){};
};

inline Node combine(const Node &nl, const Node &nr) {
  if (nl.undef) return nr;
  if (nr.undef) return nl;
  Node m;
  m.value = gcd(nl.value, nr.value);
  m.undef = false;
  return m;
}

template <typename T = Node, auto F = combine>
struct SegTree {
  int n;
  vector<T> st;
  SegTree(int _n) : n(_n), st(n << 1) {}

  void assign(int p, const T &k) {
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
