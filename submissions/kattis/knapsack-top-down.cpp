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

const int MAXN(2000), MAXM(2000);
ll memo[MAXN][MAXM + 1];
char choosen[MAXN][MAXM + 1];
ll knapSack(int u, int w, vll &VS, vi &WS) {
  if (u < 0) return 0;
  if (memo[u][w] != -1) return memo[u][w];

  ll a = 0, b = 0;
  a = knapSack(u - 1, w, VS, WS);
  if (WS[u] <= w) b = knapSack(u - 1, w - WS[u], VS, WS) + VS[u];
  if (b > a) {
    choosen[u][w] = true;
  }
  return memo[u][w] = max(a, b);
}
pair<ll, vi> knapSack(int W, vll &VS, vi &WS) {
  memset(memo, -1, sizeof(memo));
  memset(choosen, 0, sizeof(choosen));
  int n = len(VS);
  ll v = knapSack(n - 1, W, VS, WS);
  ll cw = W;
  vi choosed;
  for (int i = n - 1; i >= 0; i--) {
    if (choosen[i][cw]) {
      cw -= WS[i];
      choosed.emplace_back(i);
    }
  }
  return {v, choosed};
}

int32_t main(void) {
  fastio;
  int N, C;
  while (cin >> C >> N) {
    vll VS(N);
    vi WS(N);
    for (int i = 0; i < N; i++) {
      cin >> VS[i] >> WS[i];
    }
    auto [v, vs] = knapSack(C, VS, WS);
    cout << len(vs) << endl;
    for (auto xi : vs) cout << xi << ' ';
    cout << endl;
  }
}

// AC, binary knapsack
