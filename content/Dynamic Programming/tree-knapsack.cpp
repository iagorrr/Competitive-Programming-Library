#include "../Contest/template.cpp"

const int oo = 1e9;

int treeKnapsack(const vector<vector<int>> &adj, const vector<int> &weightOf,
                 int K, int root) {
    auto dfs = [&](auto &self, int u) -> vector<int> {
        vector<int> dp = {0};

        for (int v : adj[u]) {
            vector<int> vDp = self(self, v);

            int lU = min(K, (int)dp.size() - 1);
            int lV = min(K, (int)vDp.size() - 1);
            int newSz = min(K, lU + lV) + 1;

            vector<int> newDp(newSz, oo);

            for (int wU = 0; wU <= lU; wU++) {
                if (dp[wU] == oo) continue;
                for (int wV = 0; wV <= lV; wV++) {
                    if (vDp[wV] == oo) continue;

                    if (wU + wV < newSz) {
                        newDp[wU + wV] = min(newDp[wU + wV], dp[wU] + vDp[wV]);
                    }
                }
            }
            dp = move(newDp);
        }

        int totalW = weightOf[u];

        int reqSize = min(K, totalW) + 1;
        dp.resize(reqSize, oo);

        if (totalW < dp.size()) {
            dp[totalW] = 1;
        }

        return dp;
    };

    vector<int> ans = dfs(dfs, root);

    if (ans.size() <= K or ans[K] >= oo) return -1;

    return ans[K];
}
