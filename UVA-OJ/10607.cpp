// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)


ll min_cost(ll a, ll b, ll n, ll m)
{
	ll ans = LLONG_MAX;

	ll p2 = 0;
	while(n >= m)
	{
		
		ll dif = n-m;
		ll cost = dif*a + p2*b;
		ans = min(ans, cost);
		++p2; n /= 2;
	}
	return ans;
}
	
int main(){ 
    fastio;
	ll t; cin >> t; 

	for(int i = 1; i <= t; ++i)
	{
		cout << "Case " << i << '\n';
		ll n, m, l; cin >> n >> m >> l; cin.ignore();
		vector<pair<ll,string>> ans;

		for(int j = 0; j < l; ++j)
		{
			string ipt; getline(cin, ipt);

			int p = ipt.find(":");
			string name; name = ipt.substr(0, p);
			
			ipt = ipt.substr(p+1);
			p = ipt.find(",");
			ll a = stoi(ipt.substr(0, p));
			
			ipt = ipt.substr(p+1);
			ll b = stoi(ipt);
			
			ans.push_back({min_cost(a, b, n, m), name});
		}
		
		sort(ans.begin(), ans.end());
		for(auto [value, name] : ans)
			cout << name << ' ' << value << '\n';
	}
		
	
    return 0;
}
// AC.
