#include <iostream>

const int maxn(3*1'00'000);
int xs[maxn];

void solve() {
	int n, c;
	std::cin >> n >> c;

	for (int i = n-1; i >= 0; i--)
		std::cin >> xs[i];

	long long all = ((long long)(c+1) * (c+2)) / 2ll;
	int odd = 0, pair = 0;
	for (int i = 0; i < n; i++) {
		all -= (xs[i] / 2 + 1);
		all -= (c-xs[i]);
		if (xs[i] & 1) all += odd;
		else all += pair;

		pair += !(xs[i]&1);
		odd += (xs[i]&1);
	}


	std::cout << all << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}
}

// AC, inclusion exclusion
