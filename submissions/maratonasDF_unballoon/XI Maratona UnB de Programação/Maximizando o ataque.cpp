#include <bits/stdc++.h>
using namespace std;
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

vector<string> dir({"LU", "U", "RU", "R", "RD", "D", "LD", "L"});
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
const ll oo = 1e18;

const int MAXN(100), MAXM(100000);
int N, M;
ll memo[MAXN][MAXM + 1];
int choosen[MAXN][MAXM + 1];
ll knapSack(int u, int w, const vll2d &VS, const vi2d &WS) {
  if (u < 0) return 0;
  if (memo[u][w] != -1) return memo[u][w];

  ll a = 0, b = 0;
  a = knapSack(u - 1, w, VS, WS);
  for (int i = 0; i < 4; i++) {
    if (WS[u][i] <= w) {
      ll c = knapSack(u - 1, w - WS[u][i], VS, WS) + VS[u][i];
      if (c > a and c > b) {
        choosen[u][w] = i;
        b = c;
      }
    }
  }
  return memo[u][w] = max(a, b);
}
pair<ll, vector<pair<int, int>>> knapSack(int W, const vll2d &VS,
                                          const vi2d &WS) {
  memset(memo, -1, sizeof(memo));
  memset(choosen, -1, sizeof(choosen));
  int n = len(VS);
  ll v = knapSack(n - 1, W, VS, WS);
  ll cw = W;
  vector<pair<int, int>> choosed;
  for (int i = n - 1; i >= 0; i--) {
    int ch = choosen[i][cw];
    if (ch != -1) {
      cw -= WS[i][ch];
      choosed.emplace_back(i, ch);
    }
  }
  return {v, choosed};
}
auto solve() {
  cin >> N >> M;
  vll2d VS(N, vll(4));
  vi2d WS(N, vi(4));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> VS[i][j];
    }

    for (int j = 0; j < 4; j++) {
      cin >> WS[i][j];
    }
  }
  auto [v, cs] = knapSack(M, VS, WS);
  cout << v << ' ' << len(cs) << endl;
  for (auto ci : cs) {
    cout << ci.first + 1 << ' ' << ci.second << endl;
  }
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) solve();
}

// AC, binary knapsack, top down
