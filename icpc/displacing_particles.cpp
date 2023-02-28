// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> d((1<<20)+1, -1); 
ll solve(ll n, ll x, ll y){
	queue<pair<ll,ll>> q;
  d[(1<<(n-1))] = 0;
	q.push({0, 1<<(n-1)});
	while(!q.empty()){
		auto c = q.front(); q.pop();

    if(c.second == x)
      if(d[y] != -1) return lcm(c.first, d[y]);

    if(c.second == y)
      if(d[x] != -1) return lcm(d[x], c.first);

    ll u = c.second/2;
    if(d[u] == -1){
      d[u] = c.first+1;
      q.emplace(c.first+1, u);
    }
    u = ((1<<n)+c.second)/2;
    if(d[u] == -1){
        d[u] = c.first+1;
        q.emplace(c.first+1, u);
    }
	}
}
int main(){
	ll n, x, y;
	cin >> n >> x >> y;
	cout << solve(n, x, y) << '\n';
	return 0;
}

// UNTESTED.

