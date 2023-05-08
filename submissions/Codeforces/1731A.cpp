// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
#define minpq  priority_queue<ll, vll, greater<ll>()>
ll solve(vector<unsigned long long> a, int n){
  sort(a.begin(), a.end(), greater<>());

  unsigned long long ans = 0;
  for(int i = 1; i < n; ++i){
    a[0] = a[i]*a[0]; 
    a[i] = 1;
  }
  
  ans = n-1 + a[0];
  return ans * 2022;
}
int32_t main(void){ fastio;
  int t; cin >> t;
  
  while(t--){
    int n; cin >> n;
    vector<unsigned long long> a(n); for(auto &x:a) cin >> x;

    cout << solve(a, n) << '\n';
  }
}

// AC, greedy.
