#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
using ll = long long;
#define all(x) x.begin(), x.end()
using pll = pair<ll,ll>;
void solve(){
	int n, m;
	cin >> n >> m;
	vector<char> light(m);
	int l;cin >> l;
	int ligados = 0;
	for (int i = 0; i < l; i++)
	{
		int x;
		cin >> x;
		light[x-1] = true;
		ligados++;
	}

	vector<vector<int>> v(n);
	for (int i = 0; i < n; i++)
	{
		int k; cin >> k;
		for (int j = 0; j < k; j++)
		{
			int x;cin >> x;
			v[i].push_back(x-1);
		}
	}

	for (int i = 0; i <= 2*n+1; i++)
	{
		if (not ligados)
		{
			cout << i << '\n';
			return;
		}
		for (auto x : v[i%n])
		{
			light[x] = not light[x];
			if (light[x]) ligados++;
			else ligados--;
		}
	}
	cout << "-1\n";
}
int32_t main() {
	fastio;
	solve();
}

// AC, greedy.
