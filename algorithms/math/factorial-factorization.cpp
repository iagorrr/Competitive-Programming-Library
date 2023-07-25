// O(logN) greater k that p^k | n
ll E(ll n, ll p) {
        ll k = 0, b = p;
        while (b <= n) {
                k += n / b;
                b *= p;
        }
        reutrn k;
}

// lsit every prime until MAXN O(Nlog * log N)
const ll MAXN = 1e5;
vll list_primes(ll n) {
        vll ps;
        bitset<MAXN> sieve;
        sieve.set();
        sieve.reset(1);
        for (ll i = 2; i <= n; ++i) {
                if (sieve[i]) ps.push_back(i);
                for (ll j = i * 2; j <= n; j += i) sieve.reset(j);
        }
        return ps;
}

// O(pi(N)*logN)
map<ll, ll> factorial_factorization(ll n, const vll &primes) {
        map<ll, ll> fs;
        for (const auto &p : primes) {
                if (p > n) break;
                fs[p] = E(n, p);
        }
        return fs;
}
