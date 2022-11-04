// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll n, ll x, ll y){
	if(x == (1<<(n-1)) and y == (1<<(n-1))) return 0;

	map<ll, bool> found;

	queue<pair<ll,ll>> q;
	q.push({0, 1<<(n-1)});
	ll ans = LLONG_MAX;

	while(!q.empty()){
		auto c = q.front();
		// cout << c.first << ' ' << c.second << '\n';
		q.pop();
		if(c.second == x || c.second == y){
			if(found[c.first]) return c.first; // found x or y with c.first operations before.
			found[c.first] = true;
		}
		q.push({c.first+1, c.second/2});
		q.push({c.first+1, ((1<<(n))-c.second)/2});
	}

}
int main(){
	ll n, x, y;
	cin >> n >> x >> y;

	cout << solve(n, x, y) << '\n';
	return 0;
}

// TLE, 5
