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
const int MAXN(1'00'000);

const ll D = 330;
ll psum[MAXN][D], psum2[MAXN][D];

auto run() {
  int n, q;

  cin >> n >> q;

  vll xs(n);
  for (auto &xi : xs) cin >> xi;

  for (int i = 0; i < n; i++) {
    for (int j = 1; j < D; j++) {
      psum[i][j] =
        (i - j >= 0 ? psum[i - j][j] : 0ll) + xs[i];

      psum2[i][j] = (i - j >= 0 ? psum2[i - j][j] : 0ll) +
                    xs[i] * (i / j + 1);
    }
  }

  // int width = 5;
  // for (int i = 0; i < n; i++) {
  //   cout << setw(width) << i;
  // }
  // cout << '\n';
  // for (int j = 0; j < n; j++) {
  //   for (int i = 0; i < n; i++) {
  //     cout << setw(width) << psum[i][j];
  //   }
  //   cout << '\n';
  // }

  // cout << '\n';
  // for (int j = 0; j < n; j++) {
  //   for (int i = 0; i < n; i++) {
  //     cout << setw(width) << psum2[i][j];
  //   }
  //   cout << '\n';
  // }

  int s, d, k;
  while (q--) {
    cin >> s >> d >> k;
    s--;
    if (d >= D) {
      ll ans = 0;
      for (int i = 0; i < k; i++) {
        ans += xs[s + i * d] * (i + 1);
      }
      cout << ans << ' ';
      continue;
    }
    int r = s + d * (k - 1);
    ll ans =
      psum2[r][d] - (s - d < 0 ? 0 : psum2[s - d][d]);
    ll sub =
      (psum[r][d] - (s - d < 0 ? 0 : psum[s - d][d])) *
      max(0ll, (s + 1 + d - 1) / d - 1ll);

    cout << ans - sub << ' ';
  }

  cout << '\n';
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  cin >> T;

  for (int i = 1; i <= T; i++) {
    run();
  }
}

/*
 * AC
 * prefix sum
 * math
 * https://codeforces.com/contest/1921/problem/F
 * */
