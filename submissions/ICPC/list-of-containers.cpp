#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(__x) (int)__x.size()
using ll = long long;
using vll = vector<ll>;
#define all(__x) __x.begin(), __x.end()
using vc = vector<char>;

void swap_col(vector<vector<int>> &mat, int i, int j) {
  for (int a = 0; a < (int)mat.size(); a++) swap(mat[a][i], mat[a][j]);
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> mat(n, vector<int>(m));
  int l1 = 0;
  for (int i = 0; i < n; i++)
    for (auto &x : mat[i]) {
      cin >> x;
      if (x == 1) l1 = i;
    }

  ll ans = 0;
  for (int i = 0; i < m; i++) {
    int mn = i;
    for (int j = i + 1; j < m; j++) {
      if (mat[l1][j] < mat[l1][mn]) mn = j;
    }
    if (i != mn) {
      swap_col(mat, i, mn);
      ans++;
    }
  }

  for (int i = 0; i < n; i++) {
    int mn = i;
    for (int j = i + 1; j < n; j++) {
      if (mat[j][0] < mat[mn][0]) mn = j;
    }
    if (i != mn) {
      swap(mat[i], mat[mn]);
      ans++;
    }
  }

  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mat[i][j] != ++res) {
        cout << "*\n";
        return;
      }
    }
  }
  cout << ans << '\n';
}
int32_t main() {
  fastio;
  int t = 1;
  //  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
}

// AC, ad-hoc
