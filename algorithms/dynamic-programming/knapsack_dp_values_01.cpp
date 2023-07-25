array<array<int, MAX_S>, MAX_N> dp;
bool check[MAX_N][MAX_S];
pair<int, vi> knapsack(int S, const vector<pii> &xs) {
        int N = (int)xs.size();

        for (int i = 0; i <= N; ++i) dp[i][0] = 0;

        for (int m = 0; m <= S; ++m) dp[0][m] = 0;

        for (int i = 1; i <= N; ++i) {
                for (int m = 1; m <= S; ++m) {
                        dp[i][m] = dp[i - 1][m];
                        check[i][m] = false;

                        auto [w, v] = xs[i - 1];

                        if (w <= m and (dp[i - 1][m - w] + v) >= dp[i][m]) {
                                dp[i][m] = dp[i - 1][m - w] + v;
                                check[i][m] = true;
                        }
                }
        }

        int m = S;
        vi es;

        for (int i = N; i >= 1; --i) {
                if (check[i][m]) {
                        es.push_back(i);
                        m -= xs[i - 1].first;
                }
        }

        reverse(es.begin(), es.end());

        return {dp[N][S], es};
}
