const int MAXN{2010}, MAXM{2010};
ll st[MAXN][MAXM];
char ps[MAXN][MAXM];

pair<ll, vi> knapsack(int M, const vii &cs) {
  int N = len(cs) - 1;

  for (int i = 0; i <= N; ++i) st[i][0] = 0;

  for (int m = 0; m <= M; ++m) st[0][m] = 0;

  for (int i = 1; i <= N; ++i) {
    for (int m = 1; m <= M; ++m) {
      st[i][m] = st[i - 1][m];
      ps[i][m] = 0;
      auto [w, v] = cs[i];

      if (w <= m and st[i - 1][m - w] + v > st[i][m]) {
        st[i][m] = st[i - 1][m - w] + v;
        ps[i][m] = 1;
      }
    }
  }

  int m = M;
  vi is;
  for (int i = N; i >= 1; --i) {
    if (ps[i][m]) {
      is.push_back(i);
      m -= cs[i].first;
    }
  }

  reverse(all(is));

  // max value, items
  return {st[N][M], is};
}
