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
#define snd second
#define fst first
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)

vector<string> dir({"LU", "U", "RU", "R", "RD", "D", "LD", "L"});
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
const ll oo = 1e18;
const int maxn(12);
const int maxm(1e3);
ll N, M;
vll cs(maxm);
vll2d us(maxm);
auto solve() {
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    cin >> cs[i];
    int k;
    cin >> k;
    while (k--) {
      ll x;
      cin >> x;
      us[i].eb(x - 1);
    }
  }

  vll dp((1 << N), oo);
  dp[0] = 0;
  ll mmaxk = (1 << N);
  for (ll m = 0; m < mmaxk; m++) {
    for (int i = 0; i < M; i++) {
      ll ci = cs[i];
      ll m2 = m;
      for (auto ui : us[i]) {
        m2 |= (1ll << ui);
      }
      dp[m2] = min(dp[m2], dp[m] + ci);
    }
  }

  cout << (dp[mmaxk - 1] == oo ? -1 : dp[mmaxk - 1]) << endl;
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) solve();
}

// AC, dp, knapsack
