#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...) 42
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
int lg2(ll x) {
  return __builtin_clzll(1) - __builtin_clzll(x);
}

// vector<string> dir({"LU", "U", "RU", "R", "RD", "D",
// "LD", "L"}); int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}; int
// dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<string> dir({"U", "R", "D", "L"});
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const ll oo = 1e18;
int T(1);
const int MAXN(1'000'000);

template <class T>
struct MergeSortTree {
  int n;
  vector<vector<T>> st;

  MergeSortTree(vector<T> &xs) : n(len(xs)), st(n << 1) {
    for (int i = 0; i < n; i++)
      st[i + n] = vector<T>({xs[i]});

    for (int i = n - 1; i > 0; i--) {
      st[i].resize(len(st[i << 1]) + len(st[i << 1 | 1]));
      merge(all(st[i << 1]), all(st[i << 1 | 1]),
            st[i].begin());
    }
  }

  int count(int i, T a, T b) {
    return upper_bound(all(st[i]), b) -
           lower_bound(all(st[i]), a);
  }

  int inrange(int l, int r, T a, T b) {
    int ans = 0;

    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) ans += count(l++, a, b);
      if (r & 1) ans += count(--r, a, b);
    }

    return ans;
  }
};


auto solve() {}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif
  int N, Q;
  cin >> N >> Q;
  vll xs(N);
  for (auto &xi : xs) cin >> xi;
  vll ys(N);
  map<ll, ll> appears;
  for (int i = N - 1; i >= 0; i--) {
    ll xi = xs[i];
    ys[i] = appears.count(xi) ? appears[xi] : oo;
    appears[xi] = i;
  }

  MergeSortTree<ll> mst(ys);
  while (Q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    int sz = r - l + 1;
    cout << sz - mst.inrange(l, r, 0, r) << '\n';
  }
}
