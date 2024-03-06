#include <iostream>

const int maxn(1'00'000);

int xs[maxn+1];
int histL[maxn+1];
int histR[maxn+1];

void solve() {
	int n;
	std::cin >> n;

	histL[0] = histR[0] = 0;
	for (int i = 1; i <= n; i++) {
		histL[i] = histR[i] =  0;
		std::cin >> xs[i];
	}

	int mexL = 0,  mexR = 0;
	for (int i = 2; i <= n; i++) {
		histR[xs[i]]++;
		while(histR[mexR]) mexR++;
	}

	histL[xs[1]]++;
	mexL += xs[1] == 0;

	int p = 1;
	while (p <= n and mexR != mexL) {
		// std::cerr << p << ' ' << mexL << ' ' << mexR << '\n';
		p++;

		histL[xs[p]]++;
		while (histL[mexL]) mexL++;

		histR[xs[p]]--;
		if (histR[xs[p]] == 0) {
			if (xs[p] < mexR) mexR = xs[p];
		}
	}

	if (mexL != mexR) {
		std::cout << -1 << '\n';
		return;
	}

	std::cout <<  2 << '\n';
	std::cout << 1 << ' ' << p << '\n';
	std::cout << p+1 << ' ' << n << '\n';
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

// AC, constructive algorithms, mex
