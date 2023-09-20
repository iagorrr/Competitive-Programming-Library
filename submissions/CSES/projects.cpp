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

// range max query, point max assign update
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

void run() {
  int n;
  cin >> n;
  vector<array<ll, 3>> xs(n);  // end, start, reward
  ll maxb = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) cin >> xs[i][j];
    swap(xs[i][0], xs[i][1]);
    maxb = max(maxb, xs[i][0]);
  }

  sort(all(xs));
  SegTree st(maxb + 1ll);
  for (int i = 0; i < n; i++) {
    auto [b, a, r] = xs[i];
    ll bb = st.query(0, a);
    st.update(b + 1, bb + r);
  }
  cout << st.query(0, 1e9 + 1 + 1 + 1) << endl;
}
int32_t main(void) {
  // fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}

// AC, greddy, dynamic segment tree
