const int MAXN{2010}, MAXM{2010};

ll st[MAXN][MAXM];

ll dp(int i, int m, int M, const vii &cs) {
  if (i < 0) return 0;

  if (st[i][m] != -1) return st[i][m];

  auto res = dp(i - 1, m, M, cs);
  auto [w, v] = cs[i];

  if (w <= m) res = max(res, dp(i - 1, m - w, M, cs) + v);

  st[i][m] = res;
  return res;
}

ll knapsack(int M, const vii &cs) {
  memset(st, -1, sizeof st);

  return dp((int)cs.size() - 1, M, M, cs);
}
