#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define df(x) "[ " << #x << ": " << x << " ] "

void solve() {
  int l, c;
  cin >> l >> c;
  vector<string> v(l);
  for (auto &x : v)
    cin >> x;
  int n;
  cin >> n;

  vector<vector<int>> ans(l, vector<int>(c, -1));
  set<pair<int, int>> res;
  for (int q = 0; q < n; q++) {
    string s;
    cin >> s;
    sort(all(s));
    for (int i = 0; i < l; i++) {
      for (int j = 0; j < c; j++) {
        string hor, ver, dia, dia2;
        for (int k = 0; k < (int)s.size(); k++) {
          if (j + s.size() <= c)
            hor += v[i][j + k];
          if (i + s.size() <= l)
            ver += v[i + k][j];
          if (i + s.size() <= l and j + s.size() <= c)
            dia += v[i + k][j + k];
          if (i + s.size() <= l and j + 1 >= s.size())
            dia2 += v[i + k][j - k];
        }

        if (hor.size())
          sort(all(hor));
        if (ver.size())
          sort(all(ver));
        if (dia.size())
          sort(all(dia));
        if (dia2.size())
          sort(all(dia2));

        if (hor == s) {
          for (int k = 0; k < (int)s.size(); k++)
            if (ans[i][j + k] == -1)
              ans[i][j + k] = q;
            else if (ans[i][j + k] != q)
              res.emplace(i, j + k);
        }
        if (ver == s) {
          for (int k = 0; k < (int)s.size(); k++)
            if (ans[i + k][j] == -1)
              ans[i + k][j] = q;
            else if (ans[i + k][j] != q)
              res.emplace(i + k, j);
        }
        if (dia == s) {
          for (int k = 0; k < (int)s.size(); k++)
            if (ans[i + k][j + k] == -1)
              ans[i + k][j + k] = q;
            else if (ans[i + k][j + k] != q)
              res.emplace(i + k, j + k);
        }
        if (dia2 == s) {
          for (int k = 0; k < (int)s.size(); k++)
            if (ans[i + k][j - k] == -1)
              ans[i + k][j - k] = q;
            else if (ans[i + k][j - k] != q)
              res.emplace(i + k, j - k);
        }
      }
    }
  }

  cout << res.size() << '\n';
}

int main() {
  int t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }
}

// AC, implementation.
