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

const int maxn(2 * 1'00'000);
int n;
ll xs[maxn];

ll kadaninho() {
  ll maxao = -oo;
  for (int i = 0; i < n; i++) maxao = max(maxao, xs[i]);
  if (maxao <= 0) return maxao;

  ll ans = 0;
  ll cur = 0;
  ll prev = 0;
  bool first = true;

  for (int i = 0; i < n; i++) {
    ans = max(ans, cur);

    if (first) {  // seto ou nao
      if (xs[i] > 0) {
        cur = xs[i];
        first = false;
        prev = xs[i];
      }
      continue;
    }

    if ((xs[i] & 1) == (prev & 1)) {  // obrigado a resetar
      if (xs[i] > 0) {
        cur = xs[i];
        first = false;
        prev = xs[i];
      } else
        first = true;
      continue;
    }

    // escolho e se pego ou reseto
    if (xs[i] + cur > 0) {
      cur = xs[i] + cur;
      prev = xs[i];
    } else {
      first = true;
      cur = 0;
    }
  }

  ans = max(ans, cur);

  return ans;
}
auto solve() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> xs[i];

  cout << kadaninho() << endl;
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

// AC, dp,  greedy, two pointers
