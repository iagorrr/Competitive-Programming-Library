// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
void solve(int a, int b) {
  vector<int> ans;
  for(int i = a; i > b; --i) ans.push_back(i);
  for(int i = b; i < a; ++i) ans.push_back(i);

  cout << ans.size() << '\n';
  for(int i = 0;i < ans.size(); ++i) cout << ans[i] << " \n"[ans.size() == i+1];
}
int main() {
  int t; cin >> t;
  
  while(t--) { 
    int a, b; cin >> a >> b;
    solve(a, b);
  }
}

// AC, implementation.
