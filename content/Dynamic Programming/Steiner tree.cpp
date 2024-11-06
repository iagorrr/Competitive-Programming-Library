template <typename T>
T steinerCost(const vector<vector<T>> &adj, const vi ks,
              T inf = numeric_limits<T>::max()) {
    int k = len(ks), n = len(adj);
    vector<vector<T>> dp(n, vector<T>(1 << k, inf));
    vi inks(n);
    trav(ki, ks) inks[ki] = 1;

    trav(ki, ks) {
        rep(j, 0, n) {
            if (count(all(ks), j) == 0) {
                dp[j][1 << ki] = adj[ki][j];
            }
        }
    }
    rep(mask, 2, (1 << k)) {
        rep(i, 0, n) {
            if (inks[i]) continue;
            for (int mask2 = (mask - 1) & mask; mask2 >= 1;
                 mask2 = (mask2 - 1) & mask) {
                int mask3 = mask ^ mask2;
                chmin(dp[i][mask], dp[i][mask2] + dp[i][mask3]);
            }
            rep(j, 0, n) {
                if (inks[j]) continue;
                chmin(dp[j][mask], dp[i][mask] + adj[i][j]);
            }
        }
    }
    T ans = inf;
    rep(i, 0, n) chmin(ans, dp[i][(1 << k) - 1]);
    return ans;
}
