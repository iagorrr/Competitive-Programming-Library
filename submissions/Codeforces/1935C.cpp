#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

void solve() {
	int n, l;
	std::cin >> n >> l;

	std::vector<std::pair<int,int>> xs(n);
	for (auto &[a, b] : xs) {
		std::cin >> b >> a;
	}

	std::sort(xs.begin(), xs.end());

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int sum = 0;		
		std::multiset<int> as;

		for (int j = i; j < n; j++) {
			sum += xs[j].second;
			as.emplace(xs[j].second);

			while (!as.empty() and
					sum + xs[j].first - xs[i].first > l) {
				sum -= *as.rbegin();
				as.extract(*as.rbegin());
			}

			ans = std::max(ans, (int)as.size());
		}
	}

	std::cout << ans << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	
	while (t--)  {
		solve();
	}

}

// AC, greddy, data structures
