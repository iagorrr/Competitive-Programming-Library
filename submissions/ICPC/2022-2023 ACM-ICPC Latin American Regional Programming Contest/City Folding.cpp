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

// vector<string> dir({"LU", "U", "RU", "R", "RD", "D", "LD", "L"});
// int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
// int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<string> dir({"U", "R", "D", "L"});
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const ll oo = 1e18;

auto solve() {
  ll n, p, h;
  cin >> n >> p >> h;
  ll p2 = (1ll << n);

  ll above = (1ll << n) - h;
  ll below = h - 1;
  ll pos = p;
  ll size = 1ll;
  vll xs;
  xs.push_back(below);
  for (int i = 0; i < n; i++) {
    size *= 2ll;
    if (below >= p2 / 2ll) {
      ll tmp = above;
      above = below - p2 / 2ll;
      below = tmp;
    } else {
      above -= p2 / 2ll;
    }

    p2 /= 2ll;
    xs.push_back(below);
  }
  reverse(all(xs));

  pos = p;
  string ans;
  for (int i = 0; i < n; i++) {
    if (xs[i] < xs[i + 1]) {
      if (pos <= size / 2ll) {
        ans = ans + 'L';
        pos = size / 2ll - pos + 1ll;
      } else {
        ans = ans + 'R';
        pos = size / 2ll - (pos - size / 2ll) + 1ll;
      }
    } else {
      if (pos <= size / 2ll) {
        ans = ans + 'R';
      } else {
        ans = ans + 'L';
        pos -= size / 2ll;
      }
    }

    size /= 2ll;
  }
  dbg(xs);
  cout << ans << endl;
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

// AC, ad-hoc
