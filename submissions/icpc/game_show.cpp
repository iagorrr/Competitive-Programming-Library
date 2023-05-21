#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vll =vector<ll>;
void solve(){
	ll n;
	cin >> n;
	vll a(n);
	for(auto &x : a) cin >> x;
	ll ans = 100;
	ll cur=  100;
	for(int i = 0; i < n ;++i) {
		cur += a[i];
		ans = max(cur, ans);
	}
	cout << ans << '\n';		
}
int main(){
	int t = 1;  


	while(t--) {
		solve();
	}
}

// AC, greedy
