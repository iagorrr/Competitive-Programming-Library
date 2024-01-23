#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, m, q;
vector<string> grid;

bool valid(int x, int y) {
  if (x < 0 or y < 0 or x >= n or y >= m) return false;
  if (grid[x][y] == '*') return false;
  return true;
}

vector<vector<int>> mark;
int qtdcomp = 0;
void spread(int x, int y) {
  mark[x][y] = qtdcomp;

  for (int i = 0; i < 4; i++) {
    int ddx = dx[i], ddy = dy[i];
    int x2 = x + ddx;
    int y2 = y + ddy;
    if (!valid(x2, y2)) continue;
    if (mark[x2][y2]) continue;
    spread(x2, y2);
  }
}
vector<ll> ptscomp;
void calc() {
  mark.resize(n);
  for (int i = 0; i < n; i++) {
    mark[i].resize(m);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == '*') continue;
      if (mark[i][j]) continue;
      ++qtdcomp;
      spread(i, j);
    }
  }

  ptscomp.resize(qtdcomp + 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!mark[i][j]) continue;
      //		cout << i << ' ' << j << " : ";
      int d = 0;
      int cij = mark[i][j];
      for (int _ = 0; _ < 4; _++) {
        int di = dx[_];
        int dj = dy[_];
        int i2 = i + di, j2 = j + dj;
        d += (mark[i2][j2] == 0);
      }

      //		cout << d << endl;
      ptscomp[cij] += d;
    }
  }
}

void run() {
  cin >> n >> m >> q;
  grid.resize(n);
  for (auto &si : grid) cin >> si;

  calc();

  /*
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << mark[i][j];
    }
    cout << endl;
  }
  */

  /*
  for (int i = 1; i<= qtdcomp; i++) {
    cout << i << ' ' << ptscomp[i] << endl;
  }
  */

  while (q--) {
    int x, y;
    cin >> x >> y;
    x--, y--;

    int cxy = mark[x][y];
    cout << ptscomp[cxy] << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  run();
}

/*
 * ac
 * graphs
 * dfs and similar
 * https://codeforces.com/problemset/problem/598/D
 * */
