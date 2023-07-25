const ll MAXN = 1e5;
vll list_primes(ll n) {  // Nlog * log N
        vll ps;
        bitset<MAXN> sieve;
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

vector<pll> factorization(ll n, const vll &primes) {
        vector<pll> ans;
        for (auto &p : primes) {
                if (n == 1) break;
                ll cnt = 0;
                while (n % p == 0) {
                        cnt++;
                        n /= p;
                }
                if (cnt) ans.emplace_back(p, cnt);
        }
        return ans;
}

ll phi(ll n, vector<pll> factors) {
        if (n == 1) return 1;
        ll ans = n;

        for (auto [p, k] : factors) {
                ans /= p;
                ans *= (p - 1);
        }

        return ans;
}
