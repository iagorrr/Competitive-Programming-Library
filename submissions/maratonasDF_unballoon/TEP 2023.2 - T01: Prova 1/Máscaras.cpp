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
ll N, D;
ll ans = oo;
bitset<20> bmask;
vector<pll> XS;

bool check(bitset<20> mask) {
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      auto [a, b] = XS[i];
      auto [c, d] = XS[j];
      ll d2 = (a - c) * (a - c) + (b - d) * (b - d);
      if (d2 > D) continue;
      if (not mask[i] and not mask[j]) return false;
    }
  }
  return true;
}

auto solve() {
  cin >> N >> D;
  D *= D;

  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    XS.emplace_back(a, b);
  }

  for (int mask = 0; mask < (1ll << N); mask++) {
    bitset<20> mask2(mask);
    if (check(mask2) and mask2.count() < ans) {
      bmask = mask2, ans = mask2.count();
    }
  }

  cout << ans << endl;
  for (int i = 0; i < N; i++) {
    if (bmask[i]) cout << i + 1 << ' ';
  }
  cout << endl;
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  // cin >> T;

  for (int i = 1; i <= T; i++) {
    solve();
  }
}
