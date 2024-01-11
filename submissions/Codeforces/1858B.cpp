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
  ll n, m, d;
  cin >> n >> m >> d;
  vll xs(m);
  for (auto &xi : xs) cin >> xi;

  vll ys(m);
  ys[0] = (xs[0] - (xs[0] != 1) + d - 1) / d + (xs[0] != 1);
  for (int i = 0; i < m - 1; i++) {
    ys[i + 1] = ys[i] + (xs[i + 1] - xs[i] + d - 1) / d;
  }

  ll ans1 = ys.back() + (n - xs.back()) / d;
  map<ll, ll> anscnt;

  ll newnext = (1 + (xs[1] - 1 + d - 1) / d);
  ll ds = newnext - ys[1];
  ll anstmp = ans1 + ds;
  anscnt[anstmp]++;

  for (int i = 0; i <= m - 3; i++) {
    newnext = ys[i] + (xs[i + 2] - xs[i] + d - 1) / d;
    ds = newnext - ys[i + 2];
    anstmp = ans1 + ds;
    anscnt[anstmp]++;
  }

  newnext = ys[m-2] + (n - xs[m-2]) / d;
  ds = newnext - ans1;
  anstmp = ans1 + ds;
  anscnt[anstmp]++;

  auto [minans, anscntf] = *anscnt.begin();
  cout << minans << ' ' << anscntf << '\n';
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
 * Math
 * https://codeforces.com/problemset/problem/1858/B
 * */
