struct Node {
  ll value;
  Node() : value(0){};  // Neutral element
  Node(ll v) : value(v){};
};

Node combine(Node &nl, Node &nr, int l, int r, int ql,
             int qr) {
  Node m;
  m.value = nl.value + nr.value;
  return m;
}
