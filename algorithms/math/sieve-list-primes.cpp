// lsit every prime until MAXN
const ll MAXN = 1e5;
vll list_primes(ll n) { // Nlog * log N
        vll ps;
        bitset<MAXN> sieve;
        sieve.set();
        sieve.reset(1);
        for (ll i = 2; i <= n; ++i) {
                if (sieve[i])
                        ps.push_back(i);
                for (ll j = i * 2; j <= n; j += i) {
                        sieve.reset(j);
                }
        }
        return ps;
}
