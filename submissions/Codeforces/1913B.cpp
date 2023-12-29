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

auto solve() {
  string s;
  cin >> s;

  int n = len(s);
  vi ps1, ps0;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '0') {
      ps0.eb(i);
    } else
      ps1.eb(i);
  }

  string t = s;
  int i, j;
  j = i = 0;
  int ans = 0;
  while (i < n and j < n) {
    int di, dj;
    di = dj = 0;
    while (!ps1.empty() and ps1.back() < j) {
      ps1.pop_back();
    }
    while (!ps0.empty() and ps0.back() < j) {
      ps0.pop_back();
    }

    if (s[i] == t[j]) {
      if (t[j] == '0') {
        if (!ps1.empty()) {
          swap(t[j], t[ps1.back()]);
          ps1.pop_back();
          di = dj = 1;
        } else {
          ans++;
          dj = 1;
        }
      } else {
        if (!ps0.empty()) {
          swap(t[j], t[ps0.back()]);
          ps0.pop_back();
          di = dj = 1;
        } else {
          ans++;
          dj = 1;
        }
      }
    } else
      di = dj = 1;
    i += di, j += dj;
  }
  cout << ans << '\n';
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  cin >> T;

  for (int i = 1; i <= T; i++) {
    solve();
  }
}

// AC, greedy
