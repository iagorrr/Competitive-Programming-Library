#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#endif
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(__x) (int)__x.size()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using vi2d = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vc = vector<char>;
#define all(a) a.begin(), a.end()
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)

// vector<string> dir({"LU", "U", "RU", "R", "RD", "D", "LD", "L"});
// int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
// int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<string> dir({"U", "R", "D", "L"});
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const ll oo = 1e18;

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

struct Node {
  ll v, pv;
  Node() : v(-1) {}
  Node(ll a, ll b) : v(a), pv(b) {}
};

struct Lazy {
  ll v, pv;
  Lazy() : v(-1) {}
  Lazy(ll a, ll b) : v(a), pv(b) {}
};

Node op(Node a, Node b) {
  if (a.v == b.v) return a.pv < b.pv ? a : b;
  return a.v > b.v ? a : b;
}

Node mapping(Lazy a, Node b, int, int) {
  // treat when there is no lazy
  if (a.v < 0) return b;
  if (a.v == b.v) return a.pv < b.pv ? Node(a.v, a.pv) : b;
  return a.v > b.v ? Node(a.v, a.pv) : b;
}

Lazy comp(Lazy a, Lazy b) {
  if (a.v < 0 and b.v >= 0) return b;
  if (b.v < 0 and a.v >= 0) return a;
  if (a.v == b.v) return a.pv < b.pv ? a : b;
  return a.v > b.v ? a : b;
}

auto solve() {
  int N, Q;
  cin >> N >> Q;
  SegTreeLazy<Node, op, Lazy, mapping, comp> seg(N);
  for (int i = 0; i < N; i++) {
    ll xi;
    cin >> xi;
    Node a(xi, i);
    seg.set(i, a);
  }

  while (Q--) {
    int T;
    cin >> T;

    ll A, B;
    cin >> A >> B;
    if (T == 1) {
      A--;
      seg.set(A, {B, A});
    } else if (T == 2) {
      A--, B--;
      cout << seg.query(A, B).v << endl;
    } else {
      A--;
      int ans = N + 1;
      int l = A, r = N - 1;
      while (l <= r) {
        int mid = (l + r) / 2;
        if (seg.query(A, mid).v >= B) {
          ans = seg.query(A, mid).pv + 1;
          r = mid - 1;
        } else
          l = mid + 1;
      }
      cout << ans << endl;
    }
  }
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  int t;
  t = 1;
  // cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
}

// AC, segment tree
