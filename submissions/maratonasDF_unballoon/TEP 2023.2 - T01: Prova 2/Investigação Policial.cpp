#include <bits/stdc++.h>
using namespace std;

using vc = vector<char>;
using vc2d = vector<vc>;
const int MAXN(50);
int N, M, K;
vc2d G(MAXN, vc(MAXN));

vc2d prod(vc2d &a, vc2d &b) {
  vc2d c(N, vc(N));
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      for (int k = 0; k < N; k++)
        c[i][j] |= (a[i][k] & b[k][j]);

  return c;
}

vc2d pow() {
  auto res = G;
  auto b = G;
  K--;

  while (K > 0) {
    if (K & 1) res = prod(res, b);
    b = prod(b, b);
    K >>= 1;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M >> K;
  while (M--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a][b]++;
  }

  auto fg = pow();

  vector<int> ans;
  for (int i = 0; i < N; i++) {
    if (fg[i][0]) ans.emplace_back(i);
  }

  cout << ans.size() << '\n';
  for (auto ansi : ans) cout << ansi + 1 << ' ';
  cout << '\n';
}

// AC, matrix exponentiation
