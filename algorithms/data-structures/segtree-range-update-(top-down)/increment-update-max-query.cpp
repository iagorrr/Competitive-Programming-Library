const ll oo = (LLONG_MAX >> 1);
using Lnode = ll;
struct Qnode {
  ll v;
  Qnode() : v(-oo) {}
  Qnode(ll _v) : v(_v) {}
};

using Unode = ll;
struct LSegTree {
  int n, ql, qr;
  vector<Qnode> st;
  vector<Lnode> lz;

  /*---8<----------------------------------------------------------->8---*/
  Qnode merge(Qnode lv, Qnode rv, int nl, int nr) {
    return Qnode(max(lv.v, rv.v));
  }

  void prop(int i, int l, int r) {
    if (st[i].v == Qnode().v) st[i].v = 0;
    st[i].v += lz[i];
    if (l != r) lz[tol(i)] += lz[i], lz[tor(i)] += lz[i];
    lz[i] = 0;
  }

  void applyV(int i, Unode v) { lz[i] += v; }

  /*---8<----------------------------------------------------------->8---*/

  LSegTree() {}
  LSegTree(int _n) : n(_n), st(_n << 2), lz(_n << 2) {}
  bool disjoint(int l, int r) { return qr < l or r < ql; }
  bool contains(int l, int r) {
    return ql <= l and r <= qr;
  }
  int tol(int i) { return i << 1; }
  int tor(int i) { return i << 1 | 1; }
  void build(vector<Qnode> &v) { build(v, 1, 0, n - 1); }
  void build(vector<Qnode> &v, int i, int l, int r) {
    if (l == r) {
      st[i] = v[l];
      return;
    }
    int m = midpoint(l, r);
    build(v, tol(i), l, m);
    build(v, tor(i), m + 1, r);
    st[i] = merge(st[tol(i)], st[tor(i)], l, r);
  }
  void upd(int l, int r, Unode v) {
    ql = l, qr = r;
    upd(1, 0, n - 1, v);
  }
  void upd(int i, int l, int r, Unode v) {
    prop(i, l, r);
    if (disjoint(l, r)) return;
    if (contains(l, r)) {
      applyV(i, v);
      prop(i, l, r);
      return;
    }
    int m = midpoint(l, r);
    upd(tol(i), l, m, v);
    upd(tor(i), m + 1, r, v);
    st[i] = merge(st[tol(i)], st[tor(i)], l, r);
  }
  Qnode qry(int l, int r) {
    ql = l, qr = r;
    return qry(1, 0, n - 1);
  }
  Qnode qry(int i, int l, int r) {
    prop(i, l, r);
    if (disjoint(l, r)) return Qnode();
    if (contains(l, r)) return st[i];
    int m = midpoint(l, r);
    return merge(qry(tol(i), l, m), qry(tor(i), m + 1, r),
                 l, r);
  }

  // optional
  void print(int l, int r) {
    for (int i = l; i <= r; i++) {
      cout << i << " : " << qry(i, i).v << "\n";
    }
  }
};
