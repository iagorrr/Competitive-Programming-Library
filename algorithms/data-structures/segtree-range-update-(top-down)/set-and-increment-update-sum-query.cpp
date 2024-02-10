struct Lnode {
  ll v;
  bool assign;
  Lnode() : v(), assign() {}  // Neutral element
  Lnode(ll _v, bool a = 0) : v(_v), assign(a){};
};
using Qnode = ll;
using Unode = Lnode;

struct LSegTree {
  int n, ql, qr;
  vector<Qnode> st;
  vector<Lnode> lz;

  /*-8<--------------------------------------------------------------->8-*/

  Qnode merge(Qnode lv, Qnode rv, int nl, int nr) {
    return lv + rv;
  }

  void prop(int i, int l, int r) {
    if (lz[i].assign) {
      st[i] = lz[i].v * (r - l + 1);
      if (l != r) lz[tol(i)] = lz[tor(i)] = lz[i];
    } else {
      st[i] += lz[i].v * (r - l + 1);
      if (l != r)
        lz[tol(i)].v += lz[i].v, lz[tor(i)].v += lz[i].v;
    }
    lz[i] = Lnode();
  }

  void applyV(int i, Unode v) {
    if (v.assign) {
      lz[i] = v;
    } else {
      lz[i].v += v.v;
    }
  }
  /*-8<--------------------------------------------------------------->8-*/

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
};
