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

ll fastpow(ll a, ll b, ll mod) {
  if(b == 1) return a;
  ll ans = (fastpow(a, b/2, mod)%mod) * (fastpow(a, b/2, mod)%mod);
  if(b&1) ans = ans%mod * a%mod;
  ans = ans % mod;
  return ans;
}
void run(){
  int n; cin >> n;
  auto ans = fastpow(2, n, 1e9+7);
  cout << ans << '\n';
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}
