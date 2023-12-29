const ll oo = 1e18;
using Lnode = ll;
struct Qnode {
  ll v;
  Qnode() : v(-oo) {}
  Qnode(ll _v) : v(_v) {}
};

using Unode = ll;
/*---------------------------------------------------------------------*/
Qnode merge(Qnode lv, Qnode rv, int nl, int nr) {
  return Qnode(max(lv.v, rv.v));
}

void prop(int i, int l, int r) {
  st[i].v += lz[i];
  if (l != r) lz[tol(i)] += lz[i], lz[tor(i)] += lz[i];
  lz[i] = 0;
}

void applyV(int i, Unode v) { lz[i] += v; }
/*---------------------------------------------------------------------*/
