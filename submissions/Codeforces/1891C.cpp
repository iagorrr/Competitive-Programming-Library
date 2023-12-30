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
const int MAXN(2'000'000);

auto run() {
  int n;
  cin >> n;
  vll xs(n);
  for (auto &xi : xs) cin >> xi;

  sort(all(xs));

  int pl = 0, pr = n - 1;
  ll ans = 0;
  ll x = 0;
  while (pl < pr) {
    ll dt = min(xs[pl], xs[pr] - x);
    x += dt;
    xs[pl] -= dt;
    ans += dt;
    if (x == xs[pr]) {
      ans++;
      x = 0;
      pr--;
    }
    pl += (xs[pl] == 0);
  }

  if (pl == pr) {
    // dbg(ans, xs[pl], x);
    if (xs[pl] == 1)
      ans++;
    else {
      ll toequal = max(0ll, (xs[pl] - x) / 2ll);
      ans += toequal + 1 + ((xs[pl] - x) & 1);
    }
  }

  cout << ans << '\n';
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

// AC, greedy
