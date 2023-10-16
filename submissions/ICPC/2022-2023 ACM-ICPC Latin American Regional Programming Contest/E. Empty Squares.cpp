#include <bits/stdc++.h>

#include <algorithm>
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
  int n, k, e;
  cin >> n >> k >> e;

  int sl = e;
  int sr = n - sl - k;

  int ans = sr + sl;

  for (int sli = sl; sli >= 0; sli--) {
    for (int sri = sr; sri >= 0; sri--) {
      for (int pl = sli; pl >= 0; pl--) {
        for (int pr = sri; pr >= 0; pr--) {
          int a = pl, b = sli - pl, c = pr, d = sri - pr;
          vector<int> xs({a, b, c, d});
          bool ok = true;
          for (int i = 0; i < 4; i++) {
            if (xs[i] == k) ok = false;
            for (int j = 0; j < 4; j++) {
              if (i == j) continue;
              if (xs[i] == xs[j] and xs[i] != 0) ok = false;
            }
          }
          if (not ok) continue;
          // dbg(xs);
          cout << sr - (a + b) + sl - (c + d) << endl;
          return;
        }
      }
    }
  }

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

// AC, brute force
