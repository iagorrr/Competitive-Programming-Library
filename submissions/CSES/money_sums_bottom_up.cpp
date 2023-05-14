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

vector<vector<char>> dp(101, vector<char>(1e5+1, 0));
void show(int x, int y){
	cout << "===================================================\n";
	for(int i = 0; i <= x; ++i) {
		for(int j = 0; j <= y; ++j) {
			cout << (int)dp[i][j] << ' ' ;
		}
		cout << '\n';
	}
	cout << "===================================================\n";
}
void run(){
	ll n; cin >> n; 
	vll a(n); INV(a);
	
	sort(all(a));
	dp[0][a[0]] = 1;
	// show(n, 20);
	for(int i = 1; i < n; ++i) {
		for(int j = 0; j <= 1e5; ++j) {
			if(j==0 or dp[i-1][j]){
				/*
					 if with one coin less i could get a[i],
					 now i can get a[i]+j with the i-th coin
				 */
				dp[i][j+a[i]] = 1;

				/*
					 if i could get it with one coin less,
					 than i can get it discarding the a[i]
				 */
				dp[i][j] = 1;
			}
		}
		// show(n, 20);
	}	


	set<ll> ans;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j <= 1e5; ++j) {
			if(dp[i][j]) ans.insert(j);
		}
	}	

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
