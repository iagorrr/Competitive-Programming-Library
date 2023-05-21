#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
using ll = long long;
#define all(x) x.begin(), x.end()
using pll = pair<ll,ll>;
void solve(){
	string a, b;
	cin >> a >> b;
	int ans = 0;
	for (int i = 0; i <= (int)a.size() - b.size(); i++)
	{
		bool ok = true;
		for (int j = 0; ok and j < (int)b.size(); j++)
			if (a[i+j] == b[j])
				ok = false;
		ans += ok;
	}
	cout << ans << '\n';
}
int32_t main() {
	fastio;
	solve();
}

// AC, strings search
