const int MAXN(1'000'000);
const ll MOD(1'000'000'009), P(31);
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

inline Node combine(Node &vl, Node &vr, int nl, int nr,
                    int ql, int qr) {
  if (vl.hash == -1) return vr;
  if (vr.hash == -1) return vl;
  Node vm;

  int nm = midpoint(nl, nr);
  int lsize = min(nm, qr) - max(nl, ql) + 1;
  vm.hash =
    (vl.hash + ((vr.hash * pows[lsize]) % MOD)) % MOD;
  return vm;
}
