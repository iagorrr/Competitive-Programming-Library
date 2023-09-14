#include <bits/stdc++.h>
using namespace std;
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
#define snd second
#define fst first
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)

const ll oo = 1e18;

struct SegTree {
  struct Data {
    ll sum;
    ll set_a, set_r, add_a, add_r;
    Data() : sum(0), set_a(oo), set_r(0), add_a(0), add_r(0) {}
  };
  int n;
  vector<Data> seg;
  SegTree(int n_) : n(n_), seg(vector<Data>(4 * n)) {}

  void prop(int p, int l, int r) {
    int sz = r - l + 1;
    ll &sum = seg[p].sum, &set_a = seg[p].set_a, &set_r = seg[p].set_r,
       &add_a = seg[p].add_a, &add_r = seg[p].add_r;

    if (set_a != oo) {
      set_a += add_a, set_r += add_r;
      sum = set_a * sz + set_r * sz * (sz + 1) / 2;
      if (l != r) {
        int m = (l + r) / 2;

        seg[2 * p].set_a = set_a;
        seg[2 * p].set_r = set_r;
        seg[2 * p].add_a = seg[2 * p].add_r = 0;

        seg[2 * p + 1].set_a = set_a + set_r * (m - l + 1);
        seg[2 * p + 1].set_r = set_r;
        seg[2 * p + 1].add_a = seg[2 * p + 1].add_r = 0;
      }
      set_a = oo, set_r = 0;
      add_a = add_r = 0;
    } else if (add_a or add_r) {
      sum += add_a * sz + add_r * sz * (sz + 1) / 2;
      if (l != r) {
        int m = (l + r) / 2;

        seg[2 * p].add_a += add_a;
        seg[2 * p].add_r += add_r;

        seg[2 * p + 1].add_a += add_a + add_r * (m - l + 1);
        seg[2 * p + 1].add_r += add_r;
      }
      add_a = add_r = 0;
    }
  }

  int inter(pii a, pii b) {
    if (a.first > b.first) swap(a, b);
    return max(0, min(a.second, b.second) - b.first + 1);
  }
  ll set(int a, int b, ll aa, ll rr, int p, int l, int r) {
    prop(p, l, r);
    if (b < l or r < a) return seg[p].sum;
    if (a <= l and r <= b) {
      seg[p].set_a = aa;
      seg[p].set_r = rr;
      prop(p, l, r);
      return seg[p].sum;
    }
    int m = (l + r) / 2;
    int tam_l = inter({l, m}, {a, b});
    return seg[p].sum = set(a, b, aa, rr, 2 * p, l, m) +
                        set(a, b, aa + rr * tam_l, rr, 2 * p + 1, m + 1, r);
  }
  void update_set(int l, int r, ll aa, ll rr) {
    set(l, r, aa, rr, 1, 0, n - 1);
  }
  ll add(int a, int b, ll aa, ll rr, int p, int l, int r) {
    prop(p, l, r);
    if (b < l or r < a) return seg[p].sum;
    if (a <= l and r <= b) {
      seg[p].add_a += aa;
      seg[p].add_r += rr;
      prop(p, l, r);
      return seg[p].sum;
    }
    int m = (l + r) / 2;
    int tam_l = inter({l, m}, {a, b});
    return seg[p].sum = add(a, b, aa, rr, 2 * p, l, m) +
                        add(a, b, aa + rr * tam_l, rr, 2 * p + 1, m + 1, r);
  }
  void update_add(int l, int r, ll aa, ll rr) {
    add(l, r, aa, rr, 1, 0, n - 1);
  }
  ll query(int a, int b, int p, int l, int r) {
    prop(p, l, r);
    if (b < l or r < a) return 0;
    if (a <= l and r <= b) return seg[p].sum;
    int m = (l + r) / 2;
    return query(a, b, 2 * p, l, m) + query(a, b, 2 * p + 1, m + 1, r);
  }
  ll query(int l, int r) { return query(l, r, 1, 0, n - 1); }
};
void run() {
  int n, q;
  cin >> n >> q;

  SegTree st(n);
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    st.update_set(i, i, x, 0);
  }

  while (q--) {
    int o;
    cin >> o;

    int a, b;
    cin >> a >> b;
    a--, b--;
    if (o == 1) {
      st.update_add(a, b, 0, 1);
    } else {
      cout << st.query(a, b) << endl;
    }
  }
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, segment tree pa
