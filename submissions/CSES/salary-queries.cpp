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
 
vector<string> dir({"LU", "U", "RU", "R", "RD", "D", "LD", "L"});
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
const ll oo = 1e18;
 
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
    (p <= left->rv ? left : right)->update(p, newVal);
    val = left->val + right->val;
  }
};
 
const int BUFFSZ(1.3e7);
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
 
SegTree st(1'000'000'000 + 1);
void run() {
  int n, q;
  cin >> n >> q;
 
  vi ps((size_t)n);
  for (int i = 0; i < n; i++) {
    int pi;
    cin >> pi;
    ps[i] = pi;
    st.update(pi, 1);
  }
 
  while (q--) {
    char c;
    int x, y;
    cin >> c >> x >> y;
    if (c == '!') {
      x--;
      st.update(ps[x], -1);
      st.update(y, 1);
      ps[x] = y;
    } else {
      cout << st.query(x, y) << endl;
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

// AC, range queries, dynamic segment tree
