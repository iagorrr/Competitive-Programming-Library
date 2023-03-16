// iagorrr e thalisson alvez :)
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
#define all(x) x.begin(), x.end()
 
void solve()
{
  int n;
  cin >> n;
  unordered_set<char> st;
  vector<string> v(n);
  for (auto &x : v) cin >> x, st.insert(x[0]);
  for (auto &x : v)
  {
    bool ans = true;
    for (auto c : x)
      if (not st.count(c))
        ans = false;
    if (ans)
    {
      cout << "Y\n";
      return;
    }
  }
  cout << "N\n";
}
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
  return 0;
}
// implementation, strings.
