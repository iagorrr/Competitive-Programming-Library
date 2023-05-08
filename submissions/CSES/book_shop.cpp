// iagorrr ;)
#include <bits/stdc++.h>
#define MAX_N 1001
#define MAX_S 100001
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using ll = long long;
using vll = vector<long long>;
using vi = vector<int>;
using pii = pair<int,int>;

array<array<int, MAX_S>, MAX_N> dp;
int knapsack(int S, const vector<pii> &xs) {
  int N = (int)xs.size();

  for (int i = 0; i <= N; ++i)
    dp[i][0] = 0;

  for (int m = 0; m <= S; ++m)
    dp[0][m] = 0;

  for (int i = 1; i <= N; ++i) {
    for (int m = 1; m <= S; ++m) {
      dp[i][m] = dp[i - 1][m];

      auto [w, v] = xs[i-1];

      if (w <= m and (dp[i - 1][m - w] + v) >= dp[i][m]) {
        dp[i][m] = dp[i - 1][m - w] + v;
      }
    }
  }

  return dp[N][S];
}

int main() {fastio;
  int m, n; cin >> n >> m;
  vector<pii> cs(n);
  for (int i = 0; i < n; ++i) {
    cin >> cs[i].first;
  }
  for(int i = 0; i < n; ++i) {
    cin >> cs[i].second;
  }

  auto ans = knapsack(m, cs);

  cout << ans << '\n';

  return 0;
}

// AC, dp, knapsack 0-1
