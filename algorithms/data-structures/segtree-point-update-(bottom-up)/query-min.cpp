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
