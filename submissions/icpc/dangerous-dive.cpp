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

void solve() {
  int n, m;
  cin >> n >> m;
  vc mark(n + 1);
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    mark[x] = true;
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (not mark[i]) {
      cout << i << ' ';
      cnt++;
    }
  }

  if (cnt == 0) {
    cout << "*\n";
  } else {
    cout << endl;
  }
}
int32_t main() {
  int t = 1;
  //  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
}

// AC, implementation
