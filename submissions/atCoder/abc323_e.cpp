#include <iostream>

const int mod(998244353);
const int maxn(1'000);
const int maxx(1'0'000);

long long sum(long long a, long long b) {
	return (a + b) % mod;
}

long long sub(long long a, long long b) {
	return (a - b) % mod;
}

long long prod(long long a, long long b) {
	return (a * b) % mod;
}

long long fpow(long long a, long long p) {
	long long ret = 1;

	while (p) {
		if (p & 1) ret = prod(ret, a);
		a = prod(a, a);
		p >>= 1;
	}

	return ret;
}

long long divmod(long long a, long long b) {
	return prod(a, fpow(b, mod-2));
}


long long xs[maxn];
long long ways[maxx + 1];
int n, x;

int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cin >> n >> x;
	for (int i = 0; i < n; i++) {
		std::cin >> xs[i];
	}

	ways[0] = 1;
	long long ans = 0;
	for (int i = 0; i <= x; i++) {
		if (i + xs[0] > x) {
			ans = sum(ans, prod(ways[i], divmod(1,n)));
		}
			
		for (int j = 0; j < n; j++) {
			auto xi = xs[j];
			if (i + xi <= maxx) {
				ways[i+xi] = sum(ways[i+xi] , 
						prod(ways[i], divmod(1, n)));
			}
		}
	}

	std::cout << ans << '\n';
}

// AC, probability, mod
