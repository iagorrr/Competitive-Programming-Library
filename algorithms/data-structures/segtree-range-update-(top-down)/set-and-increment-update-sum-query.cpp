struct Lnode {
  ll v;
  bool assign;
  Lnode() : v(), assign() {}  // Neutral element
  Lnode(ll _v, bool a = 0) : v(_v), assign(a){};
};
using Qnode = ll;
using Unode = Lnode;

/*---------------------------------------------------------------------*/
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
/*---------------------------------------------------------------------*/
