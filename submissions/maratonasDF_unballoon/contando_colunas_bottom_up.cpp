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


// bottom up.
vector<vll> dpm(1e3+1, vll(1e3+1, -1));
ll n, impa;
ll dp(ll x, ll impax){// quantas tenho, impa que posso por
	if(x == n) return 1;
	if(impax > impa) return 0;
	if(x > n) return 0;

	if(dpm[x][impax] != -1) return dpm[x][impax];

	auto t1 = dp(x+impax, impax+2);
	auto t2 = dp(x, impax+2);
	return dpm[x][impax] = t1+t2;
}
void run(){
	n; cin >> n;
	impa = n&1 ? n : n-1;
	cout << dp(0, 1) << '\n';
}
int32_t main(void){ //fastio;
  int t; t = 1;
  
  while(t--)
    run();
}

// AC, bottom up


