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

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

ll solve(vll a, ll n) {
  vll b;
  ll maxe = -1;
  ll zero = 0;
  for(auto x : a) {
    if(x != 0) b.push_back(x);
    else zero++;
    maxe = max(maxe, x);
  }
  ll m = b.size();
  if(m == 0) return 1;
  else if(zero-1 > m) { 
    return maxe == 1 ? 2 : 1;
  } 
  else {  
    return 0;
  }

}
void run(){
  ll n;
  cin >> n;
  vll a(n); INV(a);
  cout << solve(a, n) << '\n';
}
int32_t main(void){ //fastio;
  int t; t = 1;
  cin >> t;  
  while(t--)
    run();
}

// AC, ad-hoc
