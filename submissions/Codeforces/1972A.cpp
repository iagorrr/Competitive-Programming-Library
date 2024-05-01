#include <bits/stdc++.h>
using namespace std;


auto run() {
	int n;
	cin >> n;
	deque<int> ai(n);
	for (auto &xi: ai) cin >> xi;
	vector<int> bi(n);
	for (auto &xi: bi) cin >> xi;

	int ans = 0;

	while(1) {
		bool fudeu = 0;
		for(int i = 0; i < n; i++) {
			if (ai[i] > bi[i]) {
				ans++, fudeu = 1;
				break;
			}
		}
		if (!fudeu) break;
		else {
			ai.push_front(1);
		}
	}


	cout << ans << '\n';

}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt;
	cin >> tt;

	for (int ti = 1; ti <= tt; ti++) {
		run();
	}
}

// AC, greddy
