#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(ll n)
{

    if(n == 2 or n == 3)
    {
        cout << "NO SOLUTION\n";
        return;
    }
    vector<ll> ans;
    for(int i = 2; i <= n; i += 2) 
    {
		ans.push_back(i);	
	}
	for(int i = 1; i <= n; i += 2) ans.push_back(i);

    cout << ans[0];
    for(int i = 1; i < ans.size(); ++i) cout << ' '<< ans[i]; cout << '\n';
}

int32_t main()
{
    ll n; cin >> n;

    solve(n);
    return 0;
}

// AC.
