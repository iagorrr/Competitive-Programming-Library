#include <bits/stdc++.h>

using namespace std;

const int maxn(100);
string xs[maxn];
int n;

int oo = 1'000'000'000;
int vis[maxn][maxn];
bool check(int i, int j, int mask) {
  bool ok = true;
  ok &= i >= 0 and i < n;
  ok &= j >= 0 and j < n;
  if (not ok)
    return false;
  if (vis[i][j])
    return false;

  char c = tolower(xs[i][j]);
  int p = c - 'a';
  int bit = (1 << p) & mask;
  if (bit and not isupper(xs[i][j]))
    return false;
  if (not bit and isupper(xs[i][j]))
    return false;
  return true;
}

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int bfs(int mask) {
  memset(vis, 0, sizeof vis);

  queue<array<int, 3>> q;
  if (check(0, 0, mask)) {
    q.push({0, 0, 1});
  }

  while (not q.empty()) {
    auto [x, y, moves] = q.front();
    q.pop();
    if (x == n - 1 and y == n - 1)
      return moves;
    for (int i = 0; i < 4; i++) {
      int x2 = x + dx[i];
      int y2 = y + dy[i];
      if (not check(x2, y2, mask))
        continue;
      vis[x2][y2] = true;
      q.push({x2, y2, moves + 1});
    }
  }

  return oo;
}
int solve() {
  int ans = oo;
  for (int mask = 0; mask < (1 << 10); mask++) {
    ans = min(ans, bfs(mask));
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> xs[i];
  }

  int ans = solve();
  if (ans == oo)
    cout << -1 << endl;
  else
    cout << ans << endl;

  return 0;
}

/*
 * AC
 * graphs
 * brute-force
 * bitset
 * */
