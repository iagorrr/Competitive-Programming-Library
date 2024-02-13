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
const int MAXN(1'000'000);

int N, M;
int hist[5000];

auto run() {
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    string s;
    cin >> s;
    for (auto c : s) {
      hist[(int)c]++;
    }
  }

  int m1, m2, m4;
  m1 = m2 = m4 = 0;
  for (int i = 0; i < 5000; i++) {
    if (!hist[i]) continue;
    ll k = hist[i];

    if (k & 1) m1++, k--;

    if (k % 4) {
      m2++;
      k -= 2;
    }

    m4 += (k / 4);
  }
  dbg(m2, m4, m1);

  // solve the fucking middle
  int mid = (N & 1) and (M & 1);
  if (mid) {
    if (m1 != 1) return 0;
  } else if (m1)
    return 0;

  // solve the pair to pair cross
  if ((N & 1) or (M & 1)) {
    ll blockrand = 0;
    if (N & 1) blockrand += (M - mid);
    if (M & 1) blockrand += (N - mid);

    if (blockrand < m2 * 2) return 0;

    blockrand -= (m2 * 2);

    if (blockrand % 4) return 0;
    if (blockrand / 4 > m4) return 0;
    m4 -= (blockrand / 4);
  }

  // the rest fill the rest =D
  ll block4 = N * M;
  if (N & 1) block4 -= (M);
  if (M & 1) block4 -= (N);
  block4 += mid;
  dbg(block4, m4 * 4);

  if (block4 != m4 * 4) return 0;

  return 1;
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  // cin >> T;

  for (int i = 1; i <= T; i++) {
    cout << (run() ? "Yes" : "No") << '\n';
  }
}

// AC, ad-hoc, palindromes
