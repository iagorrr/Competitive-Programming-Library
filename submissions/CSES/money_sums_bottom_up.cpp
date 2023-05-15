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

set<int> money_sum(const vi &xs){
	using vc = vector<char>;
	using vvc = vector<vc>;
	int _m = accumulate(all(xs), 0);
	int _n = xs.size();
	vvc _dp(_n+1, vc(_m+1, 0));
	set<int> _ans;
	_dp[0][xs[0]] = 1;
	for(int i = 1; i < _n; ++i) {
		for(int j = 0; j <= _m; ++j) {
			if(j == 0 or _dp[i-1][j]) {
				_dp[i][j+xs[i]] = 1;
				_dp[i][j] = 1;
			}
		}
	}

	for(int i = 0 ; i < _n; ++i)
		for(int j = 0; j <= _m; ++j)
			if(_dp[i][j]) _ans.insert(j);
	return _ans;
}
void run(){
	ll n; cin >> n; 
	vi a(n); INV(a);
	
	
	auto ans = money_sum(a);
	ans.erase(0);
	cout << ans.size() << '\n';
	for(auto ai : ans) cout << ai << ' ';
	cout << '\n';
}
int32_t main(void){ //fastio;
  int t; t = 1;
  
  while(t--)
    run();
}

// AC, dp, bottom up.
