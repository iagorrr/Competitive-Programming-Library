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

ll solve(ll E, ll D, ll k, ll n) {
  ll ans = E+D;
  unordered_set<ll> tiles;
  for(ll i = 1; i <= E; ++i) tiles.insert(i);
  tiles.erase(k);

  for(ll e = E; e >= 0; e--) { // how much fill at E

    for(ll i = e; i >= 0; i--) { // wich tile use  at e.
      if(i == k or e-i == k or i == e-i) continue;

      if(ans <= n-k-e-D) return ans;
      
      tiles.erase(i);
      
      if(tiles.count(e-i) or e-i == 0) { // have both tiles so can fill e.
        tiles.erase(e-i); 
        for(ll d = D; d >= 0; d--) { // how much fill at D.

          if(ans <= n-k-e-d) continue; 

          for(ll j = d; j >= 0; j--) { // wich tiles use at d.
            if(j == k or d-j == k or j == d-j) continue;
            if((tiles.count(j) or j == 0) and (d-j == 0 or tiles.count(d-j))) {
              // dbg_out(n, k ,e ,d);
              ans = min(ans ,  n - (k+e+d));
            } 
          }
        }

        ans = min(ans, E-e+D);
      }
      tiles.insert(e-i);
      tiles.insert(i);
    }
  }

  return ans;
}
void run(){
  ll n,  k , e; cin >> n >> k >> e;
  ll d = n-k-e;
  cout <<  solve(max(e, d), min(d, e), k, n);
  
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}
// AC, brute force.
