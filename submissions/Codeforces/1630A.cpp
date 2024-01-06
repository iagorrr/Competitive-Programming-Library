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
  int n, k;
  cin >> n >> k;

  if (n == 4) {
    switch (k) {
      case 0:
        cout << 0 << ' ' << 3 << '\n';
        cout << 1 << ' ' << 2 << '\n';
        break;

      case 1:
        cout << 0 << ' ' << 2 << '\n';
        cout << 1 << ' ' << 3 << '\n';
        break;

      case 2:
        cout << 0 << ' ' << 1 << '\n';
        cout << 2 << ' ' << 3 << '\n';
        break;

      case 3:
        cout << -1 << '\n';
        break;
    }
    return;
  }

  if (k == n - 1) {
    cout << n - 2 << ' ' << n - 1 << '\n';
    cout << 1 << ' ' << n - 3 << '\n';
    cout << 2 << ' ' << 0 << '\n';
    for (int i = 3; i < n / 2; i++) {
      cout << i << ' ' << n - i - 1 << '\n';
    }
    return;
  }

  cout << k << ' ' << n - 1 << '\n';
  for (int i = 1; i < n / 2; i++) {
    if (i == k) {
      cout << 0 << ' ' << n - i - 1 << '\n';
      continue;
    }
    if (n - i - 1 == k) {
      cout << i << ' ' << 0 << '\n';
      continue;
    }
    cout << i << ' ' << n - i - 1 << '\n';
  }
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
 * bitmasks
 * constructive algorithms
 * https://codeforces.com/problemset/problem/1630/A
 * */
