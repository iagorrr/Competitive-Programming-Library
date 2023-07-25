/*
   find every possible sum using
   the given values only once.
*/
set<int> money_sum(const vi &xs) {
        using vc = vector<char>;
        using vvc = vector<vc>;
        int _m = accumulate(all(xs), 0);
        int _n = xs.size();
        vvc _dp(_n + 1, vc(_m + 1, 0));
        set<int> _ans;
        _dp[0][xs[0]] = 1;
        for (int i = 1; i < _n; ++i) {
                for (int j = 0; j <= _m; ++j) {
                        if (j == 0 or _dp[i - 1][j]) {
                                _dp[i][j + xs[i]] = 1;
                                _dp[i][j] = 1;
                        }
                }
        }

        for (int i = 0; i < _n; ++i)
                for (int j = 0; j <= _m; ++j)
                        if (_dp[i][j]) _ans.insert(j);
        return _ans;
}
