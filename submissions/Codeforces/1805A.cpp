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

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

void run(){
  ll n; cin >> n;
  vll a(n); INV(a);
  
  vll cnt(9);
  for(auto ai : a) {
    for(ll i = 0; i <= 8; ++i) {
      if(ai&(1ll<<i)) cnt[i]++;
    }
  }
  ll ans = 0;
  for(int i = 0; i <= 8; ++i) {
    if(cnt[i]&1 and (n-cnt[i])&1){
      cout << -1 << '\n';
      return;
    }

    if(cnt[i]&1) ans = ans|(1ll<<i);
  }

  cout << ans << '\n';
}
int32_t main(void){ fastio;
  int t; t = 1;
  cin >> t;  
  while(t--)
    run();
}

// AC, ad-hoc, bitset, bitmask
