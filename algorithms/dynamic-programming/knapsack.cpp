// v is a vector of pairs of value and weight
auto knapsack(const vector<pair<ll, int>> &v, int capacity) {
  vector<vector<ll>> dp(v.size()+1, vector<ll>(capacity+1));
  for (int i = 1; i <= (int)v.size(); ++i) {
    for (int j = 1; j <= capacity; ++j) {
      if (v[i-1].second > j)
        dp[i][j] = dp[i-1][j];
      else
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i-1].second] + v[i-1].first);
    }
  }

  vector<int> items;
  for (int i = (int)v.size(), j = capacity; i; --i) {
    if (dp[i][j] != dp[i-1][j]) {
      items.push_back(i-1);
      j -= v[i-1].second;
    }
  }

  return items;
}
