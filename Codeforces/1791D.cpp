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
  string s; cin >> s;

  vector<vector<int>> h('z'-'a'+1, vector<int>(n));
  for(int i = 0; i < n; ++i)
    h[s[i]-'a'][i]++;

  for(int i = 1; i < n; ++i) {
    for(int c = 'a'; c <= 'z'; ++c) {
      h[c-'a'][i] += h[c-'a'][i-1];
    }
  }


  int ans = -1;
  for(int i = 0; i < n; ++i){
    int a = 0;
    int b = 0;

    for(int c = 'a'; c <= 'z'; ++c) {
      a += min(h[c-'a'][i], 1);
      b += (min(h[c-'a'][n-1]-h[c-'a'][i], 1));
    }
    ans = max(ans, a+b);
  }
  
  cout << ans << '\n';
}
int32_t main(void){ fastio;
  int t; t = 1;
  cin >> t;  
  while(t--)
    run();
}
// AC, strings, prefix sum.
