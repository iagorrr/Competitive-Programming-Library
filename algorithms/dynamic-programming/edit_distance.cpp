int edit_distance(const string &a, const string &b) {
        int n = a.size();
        int m = b.size();
        vector<vi> dp(n + 1, vi(m + 1, 0));

        int ADD = 1, DEL = 1, CHG = 1;
        for (int i = 0; i <= n; ++i) {
                dp[i][0] = i * DEL;
        }
        for (int i = 1; i <= m; ++i) {
                dp[0][i] = ADD * i;
        }

        for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                        int add = dp[i][j - 1] + ADD;
                        int del = dp[i - 1][j] + DEL;
                        int chg = dp[i - 1][j - 1] +
                                  (a[i - 1] == b[j - 1] ? 0 : 1) * CHG;
                        dp[i][j] = min({add, del, chg});
                }
        }

        return dp[n][m];
}
