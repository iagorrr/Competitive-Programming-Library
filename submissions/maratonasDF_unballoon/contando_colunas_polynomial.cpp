// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

// polynomial solution
/*
	 (1+x1)(1+x3)(1+x5)(1+x7)
	 1 + x3 + x1 + x4 (1+x5)(1+x7)
	 1 + x5 + x3 + x8 + x1 + x6 + x4 + x9 (1+x7)
	 1 + x5 + x3 + x8 + x1 + x6 + x4 + x9 (1+x7)
	 1 + x7 + x5 + x12 + x3 + x10 + x8 + x15 + x1 + x8 + x6 + x13 + x4 + x11 + x9 + x16
 */

using ll = unsigned long long;
using vll = vector<ll>;
using polynomial = vll;
void run(){
  ll n; cin >> n;
  ll k = n&1 ? n : n-1;


  vll ans(2*n+1);
  ans[0] = ans[1] = 1;
  for(ll i = 3; i <= k; i += 2) {
    for(ll j = n; ~j; --j) {
      ans[i+j] += ans[j]; 
    }
  }
  
  cout << ans[n] << '\n';
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}


// WA no test 6
