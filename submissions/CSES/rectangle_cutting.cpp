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

vector<vll> dpm(501, vll(501, -1));
ll dp(ll a, ll b) {
	// already same size.
	if(a == b) return 0;

	if(dpm[a][b] != -1) return dpm[a][b];

	ll ans = LLONG_MAX;
	for(ll i = 1; i < b; ++i){
		ll t1 = dp(a, i);
		ll t2 = dp(a, b-i);
		ans = min(ans, t1+t2+1);
	}
	
	for(ll i = 1; i < a; ++i){
		ll t1 = dp(i, b);
		ll t2 = dp(a-i, b);
		ans = min(ans, t1+t2+1);
	}

	return dpm[a][b] = ans;
}
void run(){
	ll a, b; cin >> a >> b;
 	cout << dp(a, b) << '\n';	
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}

// AC, dp, top-down
