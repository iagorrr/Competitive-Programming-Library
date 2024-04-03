#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll maxn(1'000'000'000'000);
const ll maxsqrt(1'000'000);

vector<ll> primes;
void gen_primes() {
	bitset<maxsqrt+1> mark;
	for (int i = 2; i <= maxsqrt; i++) {
		if (mark[i]) continue;
		primes.emplace_back(i);
		for (int j = i; j <= maxsqrt; j+= i) {
			mark[i] = 1;
		}
	}
}

int main() {
	gen_primes();

	ll n;
	cin >> n;

	ll pn = 0;
	for (auto pi : primes) {
		if (n % pi) continue;
		pn++;
		while (n % pi == 0) {
			n /= pi;
		}
	}
	pn += (n!=1);

	cout << (1ll<<pn) - 1 - pn << '\n';

}


// AC, number theory, combinatorics
