// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
#define INV(a) for(auto &x : a) cin >> x
#define all(a) a.begin(), a.end()

void run(){
  int n; cin >> n;
  vi a(n); INV(a);

  set<int> ans; for(int i = 1; i <= n; ++i) ans.insert(i);
  set<int> pcall;
  set<int> icall;

  for(int i = 0; i < n; ++i) {
    if(not pcall.count(i)) {
      pcall.insert(a[i]-1);
      ans.erase(a[i]);
    }
  }
  cout << ans.size() << '\n';
  for(auto x : ans) cout << x << ' ';
  cout << '\n';
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}
// implementation.
