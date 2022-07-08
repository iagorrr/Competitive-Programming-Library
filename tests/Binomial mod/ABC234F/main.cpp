#include "../../../content/Contest/template.cpp"
#include "../../../content/Math/Binomial mod.cpp"

constexpr int ASZ = 'z' - 'a';
int hs[ASZ + 1];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  for (auto c : s) hs[c - 'a']++;

  vector<vector<int>> dp(s.size() + 1,
                         vector<int>(ASZ + 1));
  for (int j = 0; j <= ASZ; j++) dp[0][j] = 1;

  for (int i = 1; i <= s.size(); i++) {
    dp[i][0] = hs[0] >= i;
  }

  int ans = 0;
  for (int i = 1; i <= (int)s.size(); i++) {
    for (int j = 1; j <= ASZ; j++) {
      auto& cur = dp[i][j];
      for (int k = 0; k <= min(i, hs[j]); k++) {
        int p = ((long long)dp[i - k][j - 1] *
                 binom(i, k)) %
                MOD;
        cur = (cur + p);
        if (cur >= MOD) cur -= MOD;
      }
    }
    ans = (ans + dp[i]['z' - 'a']);
    if (ans >= MOD) ans -= MOD;
  }

  cout << ans << '\n';
}

// AC, dynamic programming, strings, combinatorics
