#include <bits/stdc++.h>

#include <functional>
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
const ll MOD(998244353);

set<int> CU;
map<int, vi> appears;
vector<pair<int, vi>> appears2;
ll p2s[MAXN + 1];
int N;

auto run() {
  cin >> N;

  p2s[0] = 1;
  for (int i = 1; i <= N; i++) {
    CU.emplace(i);
    p2s[i] = (p2s[i - 1] << 1ll) % MOD;
  }

  for (int i = 1; i <= N; i++) {
    int x;
    cin >> x;
    appears[x].emplace_back(i);
  }

  for (auto &[v, xs] : appears) {
    appears2.emplace_back(v, xs);
  }

  sort(all(appears2), greater<>());

  ll ans = 0;
  for (auto &[num, pos] : appears2) {
    set<int> divisors;
    for (auto p : pos) {
      for (ll i = 1; i * i <= p; i++) {
        if (p % i == 0) {
          if (CU.count(i)) divisors.emplace(i);
          if (CU.count(p / i)) divisors.emplace(p / i);
        }
      }
    }

    ll a = (p2s[len(divisors)] + MOD - 1) % MOD;
    ll b = p2s[len(CU) - len(divisors)];
    ll c = (((a * b) % MOD) * num) % MOD;
    ans = (ans + c) % MOD;
    for (auto div : divisors) CU.erase(div);
  }

  cout << ans << '\n';
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif
  // cin >> T;

  for (int i = 1; i <= T; i++) {
    run();
  }
}
// math, combinatorics, number theory
