#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define endl '\n'
#define fastio                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);
// #define int long long
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
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define rep(i, begin, end)                              \
  for (__typeof(begin) i = (begin) - ((begin) > (end)); \
       i != (end) - ((begin) > (end));                  \
       i += 1 - 2 * ((begin) > (end)))

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

auto run() {
  int N;
  cin >> N;

  vector<array<int, 3>> XS(N);
  for (int i = 0; i < N; i++) {
    cin >> XS[i][0] >> XS[i][1];
    XS[i][2] = i;
  }

  vi contains(N), contained(N);

  sort(all(XS), [](const array<int, 3> &a1,
                   const array<int, 3> &a2) {
    if (a1[0] != a2[0])
      return a1[0] < a2[0];
    else
      return a1[1] > a2[1];
  });

  dbg(XS);

  int bigR = -1;
  for (int i = 0; i < N; i++) {
    int id = XS[i][2];
    contained[id] = bigR >= XS[i][1];
    bigR = max(bigR, XS[i][1]);
  }

  int lowR = 2 * 1'000'000'000;
  for (int i = N - 1; i >= 0; i--) {
    int id = XS[i][2];
    contains[id] = lowR <= XS[i][1];
    lowR = min(lowR, XS[i][1]);
  }

  for (int i = 0; i < N; i++) {
    cout << contains[i] << " \n"[i == N - 1];
  }
  for (int i = 0; i < N; i++) {
    cout << contained[i] << " \n"[i == N - 1];
  }
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  // cin >> T;

  for (int t = 1; t <= T; t++) {
    run();
  }
}

// AC, sorting
