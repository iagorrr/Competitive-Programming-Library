/*8<
  @Title:

    Range Sum Query Point Sum Update

  @Description:

    Answers range queries in ranges until $10^9$
    (maybe more)

  @Time:

    Query and update in $O(n \cdot \log{n})$
>8*/
struct node;
node *newNode();

struct node {
  node *left, *right;
  int lv, rv;
  ll val;

  node() : left(NULL), right(NULL), val(0) {}

  inline void init(int l, int r) {
    lv = l;
    rv = r;
  }

  inline void extend() {
    if (!left) {
      int m = (rv - lv) / 2 + lv;
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
    return left->query(l, r) + right->query(l, r);
  }

  void update(int p, ll newVal) {
    if (lv == rv) {
      val += newVal;
      return;
    }

    extend();
    (p <= left->rv ? left : right)
        ->update(p, newVal);
    val = left->val + right->val;
  }
};

const int BUFFSZ(1.3e7);
node *newNode() {
  static int bufSize = BUFFSZ;
  static node buf[(int)BUFFSZ];
  // assert(bufSize);
  return &buf[--bufSize];
}

struct SegTree {
  int n;
  node *root;
  SegTree(int _n) : n(_n) {
    root = newNode();
    root->init(0, n);
  }
  ll query(int l, int r) {
    return root->query(l, r);
  }
  void update(int p, ll v) { root->update(p, v); }
};
