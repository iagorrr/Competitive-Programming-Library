// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
#define minpq  priority_queue<ll, vll, greater<ll>()>

//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)
ll solve( vector<ll> a, ll n)
{
    ll ans = 0;

    for(int i = 0; i < n-1; ++i)
    {
		if((a[i]&1) == (a[i+1]&1))
		{
			ans++;
			a[i+1] *= a[i];
		}
	}
	return ans;
}
int main(){ 
    fastio;
    ll t; cin >> t;

    while(t--)
    {
        ll n; cin >> n;
        vector<ll> a(n); for(auto &x : a) cin >> x;

        cout << solve(a, n) << '\n';

    }
    return 0;
}

// AC.
