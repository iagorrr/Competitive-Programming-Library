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
const int MAXN(10000);
int N;
vll XS(MAXN);
auto solve() {
  ll sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> XS[i];
    XS[i] += 1'00'000;
    sum += XS[i];
  }

  if (sum % N) {
    cout << -1 << endl;
    return;
  }

  ll ans = 0;
  ll av = sum / N;
  for (int i = 0; i < N; i++) {
    auto xi = XS[i];
    ans += abs(av - xi);
  }

  cout << ans / 2 + 1 << endl;
}
int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  while (cin >> N) {
    solve();
  }
}

// AC, Ad-hoc, math
