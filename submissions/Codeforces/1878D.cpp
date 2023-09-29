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
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)

vector<string> dir({"LU", "U", "RU", "R", "RD", "D", "LD", "L"});
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
const ll oo = 1e18;

template <typename T = ll>
struct SegTree {
  int N;
  T nu;
  T nq;
  vector<T> st, lazy;
  SegTree(const vector<T> &xs)
    : N(len(xs)), nu(0), nq(0), st(4 * N, nu), lazy(4 * N, nu) {
    for (int i = 0; i < len(xs); ++i) update(i, i, xs[i]);
  }

  SegTree(int n) : N(n), nu(0), nq(0), st(4 * N, nu), lazy(4 * N, nu) {}

  void update(int l, int r, ll value) { update(1, 0, N - 1, l, r, value); }

  T query(int l, int r) { return query(1, 0, N - 1, l, r); }

  void update(int node, int nl, int nr, int ql, int qr, ll v) {
    propagation(node, nl, nr);

    if (ql > nr or qr < nl) return;

    if (ql <= nl and nr <= qr) {
      st[node] += (nr - nl + 1) * v;

      if (nl < nr) {
        lazy[left(node)] += v;
        lazy[right(node)] += v;
      }

      return;
    }

    update(left(node), nl, mid(nl, nr), ql, qr, v);
    update(right(node), mid(nl, nr) + 1, nr, ql, qr, v);

    st[node] = st[left(node)] + st[right(node)];
  }

  T query(int node, int nl, int nr, int ql, int qr) {
    propagation(node, nl, nr);

    if (ql > nr or qr < nl) return nq;

    if (ql <= nl and nr <= qr) return st[node];

    T x = query(left(node), nl, mid(nl, nr), ql, qr);
    T y = query(right(node), mid(nl, nr) + 1, nr, ql, qr);

    return x + y;
  }

  void propagation(int node, int nl, int nr) {
    if (lazy[node]) {
      st[node] += (nr - nl + 1) * lazy[node];

      if (nl < nr) {
        lazy[left(node)] += lazy[node];
        lazy[right(node)] += lazy[node];
      }

      lazy[node] = nu;
    }
  }

  int left(int p) { return p << 1; }
  int right(int p) { return (p << 1) + 1; }
  int mid(int l, int r) { return (r - l) / 2 + l; }
};
const int MAXN(200000);
string S;
int N, K;
vll LS(MAXN);
vll RS(MAXN);
pll get(int x) {
  int l = 0;
  int r = K - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (LS[mid] <= x and x <= RS[mid]) return {LS[mid], RS[mid]};
    if (LS[mid] > x) {
      r = mid - 1;
    } else
      l = mid + 1;
  }
  return {-1, -1};
}
auto solve() {
  cin >> N >> K;
  cin >> S;
  S = '^' + S;
  for (int i = 0; i < K; i++) cin >> LS[i];
  for (int i = 0; i < K; i++) cin >> RS[i];
  int Q;
  cin >> Q;
  SegTree st(N + 1);
  while (Q--) {
    ll X;
    cin >> X;
    auto [li, ri] = get(X);
    auto a = min(X, li + ri - X);
    auto b = max(X, li + ri - X);
    auto c = (a + b) / 2;
    st.update(a, c, 1);
  }

  for (int i = 1; i <= N; i++) {
    if (not(st.query(i, i) & 1)) continue;
    auto [li, ri] = get(i);
    int d = i - li;
    int r = ri - d;
    swap(S[i], S[r]);
  }
  cout << S.substr(1) << endl;
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  cin >> t;
  while (t--) solve();
}

// AC, data-structures
