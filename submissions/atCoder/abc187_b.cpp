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

// vector<string> dir({"LU", "U", "RU", "R", "RD", "D",
// "LD", "L"}); int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}; int
// dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<string> dir({"U", "R", "D", "L"});
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const ll oo = 1e18;
int T(1);

auto solve() {
  int n;
  cin >> n;

  vector<pll> xs(n);
  for (auto &[a, b] : xs) cin >> a >> b;

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    auto [a, b] = xs[i];
    for (int j = i + 1; j < n; j++) {
      auto [c, d] = xs[j];
      ans +=
        -1 <= (double)(d - b) / (double)(c - a) and (double)(d - b) / (double)(c - a) <= 1;
    }
  }

  cout << ans << endl;
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  // cin >> t;

  for (int i = 1; i <= T; i++) {
    solve();
  }
}

// AC, math, brute force 
