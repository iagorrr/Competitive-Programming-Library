
// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
#define INV(xxxx) for(auto &xxx : xxxx) cin >> xxx;
#define all(a) a.begin(), a.end()
#define snd second
#define fst first

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

vll dp(1e6+10, LLONG_MAX);
ll solve(ll n){
  if(dp[n] != LLONG_MAX) return dp[n]; 

  ll aux = LLONG_MAX;
  for(auto c : to_string(n)){
    ll n2 = n - (c-'0');
    if(c != '0' and n2 >= 0) {
      aux = min(aux, solve(n2)+1);
    }
  }

  return dp[n] = aux;
}
void run(){
  ll n; cin >> n;
  dp[0] = 0;
  cout << solve(n) << '\n';
   
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}

// AC, dp top down 
