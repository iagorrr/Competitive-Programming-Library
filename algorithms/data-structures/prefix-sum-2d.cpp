
struct psum2d {
  vll2d s;
  vll2d psum;
  psum2d(vll2d &grid, int n, int m)
    : s(n + 1, vll(m + 1)), psum(n + 1, vll(m + 1)) {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) s[i][j] = s[i][j - 1] + grid[i][j];

    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) psum[i][j] = psum[i - 1][j] + s[i][j];
  }

  ll query(int x1, int y1, int x2, int y2) {
    ll ans = psum[x2][y2] + psum[x1 - 1][y1 - 1];
    ans -= psum[x2][y1 - 1] + psum[x1 - 1][y2];
    return ans;
  }
};
