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

auto run() {
  int n, m;
  cin >> n >> m;
  vll xs(n);
  for (auto &xi : xs) cin >> xi;

  vll ys(m);
  for (auto &yi : ys) cin >> yi;

  ll ans = 0;
  sort(all(xs));
  sort(all(ys));
  deque<ll> d1(all(xs));
  deque<ll> d2(all(ys));
  for (int i = 0; i < n; i++) {
    ll f1 = d1.front(), b1 = d1.back();
    ll f2 = d2.front(), b2 = d2.back();
    ll a = abs(f1 - f2), b = abs(f1 - b2), c = abs(b1 - f2),
       d = abs(b1 - b2);
    if (a >= b and a >= c and a >= d) {
      ans += a;
      d1.pop_front(), d2.pop_front();
      continue;
    }
    if (b >= a and b >= c and b >= d) {
      ans += b;
      d1.pop_front(), d2.pop_back();
      continue;
    }
    if (c >= a and c >= b and c >= d) {
      ans += c;
      d1.pop_back(), d2.pop_front();
      continue;
    }

    if (d >= a and d >= b and d >= c) {
      ans += d;
      d1.pop_back(), d2.pop_back();
      continue;
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

/*
 * AC
 * greedy
 * data structures
 * */
