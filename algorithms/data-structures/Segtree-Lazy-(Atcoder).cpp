
struct Node {
  // need an empty constructor with the neutral node
  Node() : {}
};

struct Lazy {
  // need an empty constructor with the neutral lazy
  Lazy() : {}
};

// how to merge two nodes
Node op(Node a, Node b) {}

// how to apply the lazy into a node
Node mapping(Lazy a, Node b, int, int) {}

// how to merge two lazy
Lazy comp(Lazy a, Lazy b) {}

template <typename T, auto op, typename L, auto mapping, auto composition>
struct SegTreeLazy {
  static_assert(is_convertible_v<decltype(op), function<T(T, T)>>,
                "op must be a function T(T, T)");
  static_assert(
    is_convertible_v<decltype(mapping), function<T(L, T, int, int)>>,
    "mapping must be a function T(L, T, int, int)");
  static_assert(is_convertible_v<decltype(composition), function<L(L, L)>>,
                "composition must be a function L(L, L)");

  int N, size, height;
  const T eT;
  const L eL;
  vector<T> d;
  vector<L> lz;

  SegTreeLazy(const T &eT_ = T(), const L &eL_ = L())
    : SegTreeLazy(0, eT_, eL_) {}
  explicit SegTreeLazy(int n, const T &eT_ = T(), const L &eL_ = L())
    : SegTreeLazy(vector<T>(n, eT_), eT_, eL_) {}
  explicit SegTreeLazy(const vector<T> &v, const T &eT_ = T(),
                       const L &eL_ = L())
    : N(int(v.size())), eT(eT_), eL(eL_) {
    size = 1;
    height = 0;
    while (size < N) size <<= 1, height++;
    d = vector<T>(2 * size, eT);
    lz = vector<L>(size, eL);
    for (int i = 0; i < N; i++) d[size + i] = v[i];
    for (int i = size - 1; i >= 1; i--) {
      update(i);
    }
  }

  void set(int p, T x) {
    assert(0 <= p && p < N);
    p += size;
    for (int i = height; i >= 1; i--) push(p >> i);
    d[p] = x;
    for (int i = 1; i <= height; i++) update(p >> i);
  }

  T get(int p) {
    assert(0 <= p && p < N);
    p += size;
    for (int i = height; i >= 1; i--) push(p >> i);
    return d[p];
  }

  T query(int l, int r) {
    assert(0 <= l && l <= r && r < N);

    l += size;
    r += size;

    for (int i = height; i >= 1; i--) {
      if (((l >> i) << i) != l) push(l >> i);
      if ((((r + 1) >> i) << i) != (r + 1)) push(r >> i);
    }

    T sml = eT, smr = eT;
    while (l <= r) {
      if (l & 1) sml = op(sml, d[l++]);
      if (!(r & 1)) smr = op(d[r--], smr);
      l >>= 1;
      r >>= 1;
    }

    return op(sml, smr);
  }

  T query_all() { return d[1]; }

  void update(int p, L f) {
    assert(0 <= p && p < N);
    p += size;
    for (int i = height; i >= 1; i--) push(p >> i);
    d[p] = mapping(f, d[p]);
    for (int i = 1; i <= height; i++) update(p >> i);
  }
  void update(int l, int r, L f) {
    assert(0 <= l && l <= r && r < N);

    l += size;
    r += size;

    for (int i = height; i >= 1; i--) {
      if (((l >> i) << i) != l) push(l >> i);
      if ((((r + 1) >> i) << i) != (r + 1)) push(r >> i);
    }

    {
      int l2 = l, r2 = r;
      while (l <= r) {
        if (l & 1) all_apply(l++, f);
        if (!(r & 1)) all_apply(r--, f);
        l >>= 1;
        r >>= 1;
      }
      l = l2;
      r = r2;
    }

    for (int i = 1; i <= height; i++) {
      if (((l >> i) << i) != l) update(l >> i);
      if ((((r + 1) >> i) << i) != (r + 1)) update(r >> i);
    }
  }
  pair<int, int> node_range(int k) const {
    int remain = height;
    for (int kk = k; kk >>= 1; --remain)
      ;
    int fst = k << remain;
    int lst = min(fst + (1 << remain) - 1, size + N - 1);
    return {fst - size, lst - size};
  }

 private:
  void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
  void all_apply(int k, L f) {
    auto [fst, lst] = node_range(k);
    d[k] = mapping(f, d[k], fst, lst);
    if (k < size) lz[k] = composition(f, lz[k]);
  }
  void push(int k) {
    all_apply(2 * k, lz[k]);
    all_apply(2 * k + 1, lz[k]);
    lz[k] = eL;
  }
};
