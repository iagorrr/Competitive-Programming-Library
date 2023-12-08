#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int cur = 1;
    for (int j = 0; j < m; j++) {
      int xs;
      cin >> xs;
      cur &= xs != 0;
    }
    ans += cur;
  }

  cout << ans << endl;

  return 0;
}

/*
 * AC
 * ad-hoc
 * */
