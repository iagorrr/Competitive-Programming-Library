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
const ll oo = 1e12;
const int MAXN(100), MAXK(5 + 1), MAXP(5);
ll dpm[MAXN][MAXK][MAXK][MAXK][MAXK][MAXK];
int N, K, P;
vector<pair<ll, vi>> XS(MAXN, pair<ll, vi>(0, vi(MAXK)));
ll dp(int n, vi cur) {
  if (n == N) return oo;

  if (dpm[n][cur[0]][cur[1]][cur[2]][cur[3]][cur[4]] != -1)
    return dpm[n][cur[0]][cur[1]][cur[2]][cur[3]][cur[4]];

  bool ok = true;
  for (int i = 0; i < K; i++) ok &= cur[i] >= P;
  if (ok) {
    return 0;
  }

  ll a = dp(n + 1, cur);

  vi cur2 = cur;
  for (int i = 0; i < K; i++) cur2[i] = min(cur2[i] + XS[n].second[i], MAXP);
  ll b = dp(n + 1, cur2) + XS[n].first;

  ok = true;
  for (int i = 0; i < K; i++) ok &= cur2[i] >= P;
  if (ok) {
    b = XS[n].first;
  }

  return dpm[n][cur[0]][cur[1]][cur[2]][cur[3]][cur[4]] = min({a, b});
}
void solve() {
  memset(dpm, -1, sizeof(dpm));
  cin >> N >> K >> P;
  for (int i = 0; i < N; i++) {
    cin >> XS[i].first;
    for (int j = 0; j < K; j++) {
      cin >> XS[i].second[j];
    }
  }
  dp(0, vi(5, 0));

  auto ans = dpm[0][0][0][0][0][0];
  cout << (ans == oo ? -1 : ans) << endl;
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) solve();
}

// AC, knapsack
