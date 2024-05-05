#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;
const ll MAXN = 1'00'000;
ll FACT[MAXN + 1];

void precompute() {
#warning Remember to call precompute before use binommod !
  FACT[0] = 1;
  for (ll i = 1; i <= MAXN; i++) {
    FACT[i] = (FACT[i - 1] * i) % MOD;
  }
}

ll fpow(ll a, ll k) {
  ll ret = 1;
  while (k) {
    if (k & 1) ret = (ret * a) % MOD;
    a = (a * a) % MOD;
    k >>= 1;
  }
  return ret;
}

ll binommod(ll n, ll k) {
  ll upper = FACT[n];
  ll lower = (FACT[k] * FACT[n - k]) % MOD;
  return (upper * fpow(lower, MOD - 2ll)) % MOD;
}


auto run() {
	int n, k;
	cin >> n >> k;

	vector<ll> xs(n);
	map<int,int> hist;
	for (auto &xi : xs) {
		cin >> xi;
		hist[xi]++;
	}

	sort(xs.begin(), xs.end(), greater<>());

	int menor = xs[k-1];
	int qtd = count(xs.begin(), xs.begin()+k, menor);

	cout << binommod(hist[menor], qtd) << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	precompute();

	int tt = 1;
	cin >> tt;

	for (int ttt = 1; ttt <= tt; ttt++) {
		run();
	}
}

// AC, math, combinatorics, number theory
