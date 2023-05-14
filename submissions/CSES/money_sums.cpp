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

void run(){
	ll n; cin >> n;
	vll a(n); INV(a);
	set<ll> ans;



	for(int i = 0; i < n ; ++i) {
		//for(auto ai : ans) cout << ai << ' '; cout << '\n';
		ll v = a[i];
		vll topush;
		for(auto &ai : ans){
			topush.push_back(v+ai);
		}
		ans.insert(all(topush));
		ans.insert(v);
	}
	
	cout << ans.size() << '\n';
	for(auto &ai : ans) {
		cout << ai << ' ';
	}
	cout << '\n';
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}

// AC, set manipulation
