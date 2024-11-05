const int N = 1001;
ll matrix[N][N];
ll M[1001][1001][10][10];
ll op(ll a, ll b) { return gcd(a, b); }

void SparseMatrix(int n, int m) {
  int i, j, x, y;
  for (i = 0; (1 << i) <= n; i++) {
    for (j = 0; (1 << j) <= m; j++) {
      for (x = 0; (x + (1 << i) - 1) < n; x++) {
        for (y = 0; (y + (1 << j) - 1) < m; y++) {
          if (i == 0 && j == 0)
            M[x][y][i][j] = matrix[x][y];
          else if (i == 0)
            M[x][y][i][j] =
                op(M[x][y][i][j - 1],
                   M[x][y + (1 << (j - 1))][i]
                    [j - 1]);
          else if (j == 0)
            M[x][y][i][j] =
                op(M[x][y][i - 1][j],
                   M[x + (1 << (i - 1))][y][i - 1]
                    [j]);
          else {
            int tempa =
                op(M[x + (1 << (i - 1))][y][i - 1]
                    [j - 1],
                   M[x][y + (1 << (j - 1))][i - 1]
                    [j - 1]);
            int tempb = op(M[x][y][i - 1][j - 1],
                           M[x + (1 << (i - 1))]
                            [y + (1 << (j - 1))]
                            [i - 1][j - 1]);
            M[x][y][i][j] = op(tempa, tempb);
          }
        }
      }
    }
  }
  return;
}

int lg2(int x) {
  return sizeof(int) * 8 - __builtin_clz(x) - 1;
}

ll query2d(int x, int y, int x1, int y1) {
  int k = lg2(x1 - x + 1);
  int l = lg2(y1 - y + 1);

  int tempa = op(M[x][y][k][l],
                 M[x1 - (1 << k) + 1][y][k][l]);
  int tempb = op(M[x][y1 - (1 << l) + 1][k][l],
                 M[x1 - (1 << k) + 1]
                  [y1 - (1 << l) + 1][k][l]);
  return op(tempa, tempb);
}
