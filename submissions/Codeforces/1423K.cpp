#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAXN = 2e6;
using vll = vector<ll>;

vll list_primes(ll n = MAXN) {
  vll ps;
  bitset<MAXN + 1> sieve;
  sieve.set();
  sieve.reset(1);
  for (ll i = 2; i <= n; ++i) {
    if (sieve[i]) ps.push_back(i);
    for (ll j = i * 2; j <= n; j += i) {
      sieve.reset(j);
    }
  }
  return ps;
}

int ans[MAXN+1];
void precompute() {
	auto ps = list_primes();
	for (auto pi : ps) {
		ans[pi]++;
		if (pi*pi <= MAXN)
			ans[pi*pi]--;
	}
	ans[0] = 1;
	for (int i = 1; i <= MAXN; i++) {
		ans[i] = ans[i-1] + ans[i];
	}
}

auto run() {
	
	int n;
	cin >> n;

	cout << ans[n] << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	precompute();

	int t = 1;
	cin >> t;

	while (t--) {
		run();
	}
}

// AC. number theory
