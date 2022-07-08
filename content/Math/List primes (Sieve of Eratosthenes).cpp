const ll MAXN = 2e5;
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
