#include <algorithm>
#include <iostream>

constexpr int N = 510, p = 998244353;

int fp(int a, int b) {
  int ans = 1, off = a;
  while (b) {
    if (b & 1) ans = 1ll * ans * off % p;
    off = 1ll * off * off % p;
    b >>= 1;
  }
  return ans;
}

int gauss(int (&dat)[N][N], int (&ans)[N],
          int (&basis)[N][N], int n, int m) {
  int k = 1;

  static int col[N];

  for (int i = 1; i <= m && k <= n; ++i) {
    int pos = 0;

    for (int j = k; j <= n; ++j)
      if (dat[j][i]) {
        pos = j;
        break;
      }

    if (!pos) continue;

    col[k] = i;

    if (pos != k) {
      for (int j = i; j <= m + 1; ++j)
        std::swap(dat[pos][j], dat[k][j]);
    }

    int rv = fp(dat[k][i], p - 2);

    for (int j = i; j <= m + 1; ++j)
      dat[k][j] = 1ll * dat[k][j] * rv % p;

    for (int j = k + 1; j <= n; ++j)
      if (dat[j][i]) {
        int num = p - dat[j][i];

        for (int t = i; t <= m + 1; ++t)
          dat[j][t] = (dat[j][t] +
                       1ll * num * dat[k][t]) %
                      p;
      }

    ++k;
  }

  for (int i = k; i <= n; ++i)
    if (dat[i][m + 1]) return -1;

  --k;

  int R = m - k;

  for (int i = 1; i <= m; ++i) ans[i] = 0;

  for (int i = k; i; --i) {
    ans[col[i]] = dat[i][m + 1];

    for (int j = i + 1; j <= k; ++j)
      ans[col[i]] = (ans[col[i]] +
                     1ll * (p - dat[i][col[j]]) *
                         ans[col[j]]) %
                    p;
  }

  for (int i = 1; i <= R; ++i)
    for (int j = 1; j <= m; ++j) basis[i][j] = 0;

  col[k + 1] = m + 1;
  col[0] = 0;

  for (int i = 0, t = 0; i <= k; ++i) {
    for (int j = col[i] + 1; j < col[i + 1];
         ++j) {
      ++t;

      for (int l = i; l; --l) {
        int c = dat[l][j];

        for (int r = l + 1; r <= i; ++r)
          c = (c + 1ll * dat[l][col[r]] *
                       basis[t][col[r]]) %
              p;

        basis[t][col[l]] = (p - c) % p;
      }

      basis[t][j] = 1;
    }
  }

  return R;
}

int main() {
  int n, m;

  static int dat[N][N], ans[N], basis[N][N];

  std::ios::sync_with_stdio(false);

  std::cin.tie(0);

  std::cin >> n >> m;

  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      std::cin >> dat[i][j];

  for (int j = 1; j <= n; ++j)
    std::cin >> dat[j][m + 1];

  int R = gauss(dat, ans, basis, n, m);

  if (!(~R)) {
    std::cout << "-1\n";
    return 0;
  }

  std::cout << R << '\n';

  for (int j = 1; j <= m; ++j)
    std::cout << ans[j] << ' ';
  std::cout << '\n';

  for (int i = 1; i <= R; ++i) {
    for (int j = 1; j <= m; ++j)
      std::cout << basis[i][j] << ' ';
    std::cout << '\n';
  }

  return 0;
}
