#include <bits/stdc++.h>
using namespace std;
/*
	fixar a mais feia
	e dai restar pegar as mais longas
	com todas as outras sendo mais bonitas do que ela...  */

using ll = long long ;

auto run() {
	ll n, k;
	cin >> n >> k;

	vector<pair<ll,ll>> songs(n);
	for (auto &[a, b] : songs) cin >> a >> b;

	sort(songs.begin(), songs.end(), [&](const pair<ll,ll> &a, pair<ll,ll> &b) {
			return a.second == b.second ? a.first < b.first : a.second < b.second;
	});

	priority_queue<ll, vector<ll>, greater<ll>> longest;
	ll lsum = 0;

	ll ans = 0;
	for (ll i = n - 1; i >= 0; i--) {
		auto &[a, b] = songs[i];
		ans = max(ans, (lsum + a) * b);

		if ((int)longest.size() + 1 < k) {
			longest.emplace(a);
			lsum += a;
		}
		else {
			if (!longest.empty() and longest.top() < a) {
				lsum -= longest.top();
				longest.pop();
				longest.emplace(a);
				lsum += a;
			}
		}
	}

	cout << ans << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	// cin >> t;

	while (t--) {
		run();
	}
}

// AC, brute force, sorting
