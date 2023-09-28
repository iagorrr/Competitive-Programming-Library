const int MAXN{2010}, MAXM{2010};
ll st[MAXN][MAXM];
char ps[MAXN][MAXM];
pair<ll, vi> knapsack(int M, const vll &VS, const vi &WS) {
  memset(st, 0, sizeof(st));
  memset(st, 0, sizeof(st));
  int N = len(VS) - 1;  // ELEMENTS START AT INDEX 1 !

  for (int i = 0; i <= N; ++i) st[i][0] = 0;

  for (int m = 0; m <= M; ++m) st[0][m] = 0;

  for (int i = 1; i <= N; ++i) {
    for (int m = 1; m <= M; ++m) {
      st[i][m] = st[i - 1][m];
      ps[i][m] = 0;
      int w = WS[i];
      ll v = VS[i];

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
      is.emplace_back(i - 1);
      m -= WS[i];
    }
  }

  return {st[N][M], is};
}
