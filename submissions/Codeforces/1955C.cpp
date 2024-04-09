#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve() {
	ll k;
	int n;
	cin >> n >> k;

	deque<ll> xs;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		xs.push_back(x);
	}
	
	int ans = 0;

	int start = 0;
	while (!xs.empty() and k) {
		//cerr << "k: " << k << "start: " << start << '\n';
		ll front = xs.front();
		ll back = xs.back();
		
		if (xs.size() == 1) {
			ans += xs.front() <= k;
			break;
		}

		ll to_kill_front = front * 2 - (start == 0);
		ll hit_back = (to_kill_front + (start != 0)) / 2;

		ll to_kill_back = back * 2 - (start == 1);
		ll hit_front = (to_kill_back + (start != 1))/ 2;

		if (to_kill_front > k and to_kill_back > k) break;

		//cerr << "front: " << front << " back: " << back << '\n';
		//cerr << to_kill_front << ' ' << to_kill_back << '\n';
		if (to_kill_front < to_kill_back) {
			k -= to_kill_front;
			xs.pop_front();
			xs.back() -= hit_back;
			start = 1;
			ans++;
		}
		else if (to_kill_front > to_kill_back) {
			k -= to_kill_back;
			xs.pop_back();
			xs.front() -= hit_front;
			ans++;
			start = 0;
		}
	}

	cout << ans << '\n';
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}
}

/*	
	AC, ad-hoc
 */

