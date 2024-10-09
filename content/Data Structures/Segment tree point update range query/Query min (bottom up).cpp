using namespace std;
using ll = long long;
using Node = long long;
inline Node combine(const Node &nl, const Node &nr) { return nl + nr; }

struct SegTree {
  int n;
  vector<Node> st;
  SegTree(int _n) : n(_n), st(n << 1) {}

  void assign(int p, const Node &k) {
    for (st[p += n] = k; p >>= 1;) st[p] = combine(st[p << 1], st[p << 1 | 1]);
  }

  Node query(int l, int r) {
    Node ansl = Node(), ansr = Node();
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) ansl = combine(ansl, st[l++]);
      if (r & 1) ansr = combine(st[--r], ansr);
    }
    return combine(ansl, ansr);
  }
};

int firstPrefix(SegTree &st, ll s) {
  int cur = 1;
  while (cur < st.n) {
    int l = cur << 1;
    int r = cur << 1 | 1;
    if (st.st[l] >= s) {
      cur = l;
    } else {
      s -= st.st[l];
      cur = r;
    }
  }
  return cur - st.n;
}
