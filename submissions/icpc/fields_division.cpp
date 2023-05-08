// iagorrr & thalisson alves :)
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) x.begin(), x.end()

void dfs(vector<vector<int>> &g, int n, string &ans)
{
  for (auto x : g[n])
  {
    if (ans[x-1] == 'B' or x == (int)ans.size()) 
      continue;
    ans[x-1] = 'B';
    dfs(g, x, ans);
  }
}

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n+1);
  string fans(n, 'A');
  for (int i = 0; i < m; i++)
  {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  fans[n-2] = 'B';
  dfs(g, n-1, fans);
  cout << fans << '\n';
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
  return 0;
}

// AC, dfs
