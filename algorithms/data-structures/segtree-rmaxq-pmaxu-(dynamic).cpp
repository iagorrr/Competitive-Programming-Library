struct node;
node *newNode();

struct node {
  node *left, *right;
  int lv, rv;
  ll val;

  node() : left(NULL), right(NULL), val(-oo) {}

  inline void init(int l, int r) {
    lv = l;
    rv = r;
  }

  inline void extend() {
    if (!left) {
      int m = (lv + rv) / 2;
      left = newNode();
      right = newNode();
      left->init(lv, m);
      right->init(m + 1, rv);
    }
  }

  ll query(int l, int r) {
    if (r < lv || rv < l) {
      return 0;
    }

    if (l <= lv && rv <= r) {
      return val;
    }

    extend();
    return max(left->query(l, r), right->query(l, r));
  }

  void update(int p, ll newVal) {
    if (lv == rv) {
      val = max(val, newVal);
      return;
    }

    extend();
    (p <= left->rv ? left : right)->update(p, newVal);
    val = max(left->val, right->val);
  }
};

const int BUFFSZ(1e7);
node *newNode() {
  static int bufSize = BUFFSZ;
  static node buf[(int)BUFFSZ];
  assert(bufSize);
  return &buf[--bufSize];
}

struct SegTree {
  int n;
  node *root;
  SegTree(int _n) : n(_n) {
    root = newNode();
    root->init(0, n);
  }
  ll query(int l, int r) { return root->query(l, r); }
  void update(int p, ll v) { root->update(p, v); }
};
