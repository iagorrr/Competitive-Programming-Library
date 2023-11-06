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

// vector<string> dir({"LU", "U", "RU", "R", "RD", "D",
// "LD", "L"}); int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}; int
// dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<string> dir({"U", "R", "D", "L"});
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const ll oo = 1e18;

const int MAXN(10000);
int N;
ll XS[MAXN];
ll dp[2][MAXN][2];
ll psum[MAXN + 1];
auto solve() {
  for (int i = 0; i < N; i++) cin >> XS[i];
  for (int i = 1; i <= N; i++)
    psum[i] = psum[i - 1] + XS[i - 1];

  // Caso base, escolher entre dois elementos
  for (int sz = 1; sz < N; sz++) {
    for (int i = 0; i + sz < N; i++) {
      dp[1][i][0] = max(XS[i], XS[i + 1]);
    }
  }

  for (int sz = 2; sz < N; sz++) {
    int p = !(sz & 1);

    swap(dp[1], dp[0]);

    for (int i = 0; i + sz < N; i++) {
      int l = i, r = i + sz;
      ll sumlr = psum[r + 1] - psum[l];
      dp[1][i][p] = max(sumlr - dp[0][i][!p], sumlr - dp[0][i+1][!p]);
    }
  }

  cout << dp[1][0][0] << endl;
}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  int maxn = -1;
  while (cin >> N) {
    solve();
    maxn = max(N, maxn);
  }
}

// AC, dp, dynamic programming, memorization inline
