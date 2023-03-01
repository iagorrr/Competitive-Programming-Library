#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod(ll x){
	return max(x , -x);
}
ll solve(const vector<ll> a, ll n){

	ll ans = 0;
	ll current = a[0];
	ans = mod(a[0]);
	for(ll i = 1; i < n; ++i){
		ans += mod(current + a[i]);
		current += a[i];
	}

	return ans;
}

int main(){
	ll n;
	while(n != 0){
		cin >> n;
		if(n == 0) continue;

		vector<ll> a(n);
		for(auto &x : a) cin >> x;

		cout << solve(a, n) << '\n';
	}	

	return 0;
}

