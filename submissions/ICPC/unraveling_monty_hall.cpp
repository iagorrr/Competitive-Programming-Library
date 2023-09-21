#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
using ll = long long;
#define all(x) x.begin(), x.end()
using pll = pair<ll,ll>;
void solve(){
	int n;
	cin >> n;
	int ans = 0;
	while (n--)
	{
		int x;
		cin >> x;
		ans += x != 1;
	}
	cout << ans << '\n';
}
int32_t main() {
	fastio;
	solve();
	return 0;
}

// AC, ad-hoc
