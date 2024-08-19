
struct Node {
  ll tot, suf, pref, best;
  // Neutral element
  Node()
      : tot(-oo),
        suf(-oo),
        pref(-oo),
        best(-oo) {}  // Neutral element
  // for assign
  Node(ll x) {
    tot = x, suf = x, pref = x,
    best = max(0ll, x);
  }
};

Node combine(Node &nl, Node &nr) {
  if (nl.tot == -oo) return nr;
  if (nr.tot == -oo) return nl;
  Node m;
  m.tot = nl.tot + nr.tot;
  m.pref = max({nl.pref, nl.tot + nr.pref});
  m.suf = max({nr.suf, nr.tot + nl.suf});
  m.best =
      max({nl.best, nr.best, nl.suf + nr.pref});
  return m;
}
