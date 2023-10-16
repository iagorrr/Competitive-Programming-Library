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

int cday;
int n;
map<string, int> days({{"Mon", 0},
                       {"Tue", 1},
                       {"Wed", 2},
                       {"Thu", 3},
                       {"Fri", 4},
                       {"Sat", 5},
                       {"Sun", 6}});

int get(int x) {
  int xpass = -x;
  int xday = (((cday - x) % 7) + 7) % 7;

  if (xday == 1) {
    xpass += 30;
    xday = 3;
    if (xpass >= 0) return xpass;
  }

  if (xday == 3) {
    xpass += 32;
    xday = 0;
    if (xpass >= 0) return xpass;
  }

  xpass = -((-xpass) % 91);
  // if (xpass == 0) return 0;
  for (;;) {
    if (xday == 0) {
      xpass += 30;
      xday = 2;
      if (xpass >= 0) return xpass;
    }
    if (xday == 2) {
      xpass += 30;
      xday = 4;
      if (xpass >= 0) return xpass;
    }
    if (xday == 4) {
      xpass += 31;
      xday = 0;
      if (xpass >= 0) return xpass;
    }
  }
}
auto solve() {
  string s;
  cin >> s >> n;
  cday = days[s];

  int ans = 42;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ans = min(ans, get(x));
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
