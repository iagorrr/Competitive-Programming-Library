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

const int MAXN(2000);
int N;
int ans = MAXN;
string S;

bool is_palindrome(int l, int r) {
  while (l <= r) {
    if (S[l] != S[r]) return false;
    l++, r--;
  }
  return true;
}
int _dp[MAXN];
int dp(int p) {
  if (p >= N) return 0;
  if (_dp[p] != -1) return _dp[p];

  int curdp = MAXN;
  for (int i = p; i < N; i++) {
    if (is_palindrome(p, i))
      curdp = min(curdp, dp(i + 1) + 1);
  }

  return _dp[p] = curdp;
}

int mincut() {
  for (int i = 0; i < N; i++) {
    if (is_palindrome(0, i)) {
      ans = min(ans, dp(i + 1) + 1);
    }
  }
  return ans;
}

auto solve() {
  memset(_dp, -1, sizeof _dp);
  ans = MAXN;

  cin >> S;

  cout << mincut() << endl;
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif
  T = 1;
  while (cin >> N) {
    if (not N) break;
    cout << "Teste " << T++ << endl;
    solve();
    cout << endl;
  }
}

/*
 * AC
 * https://neps.academy/br/exercise/631
 * Strings
 * Palíndromo
 * Programação Dinâmica
 * */
