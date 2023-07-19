// Nlog * log N
const ll MAXN = 1e5;
vll list_primes(ll n)
{
        vll ps;
        bitset<MAXN> sieve;
        sieve.set();
        sieve.reset(1);
        for (ll i = 2; i <= n; ++i)
        {
                if (sieve[i])
                        ps.push_back(i);
                for (ll j = i * 2; j <= n; j += i)
                        sieve.reset(j);
        }
        return ps;
}

// O(pi(sqrt(n)))
map<ll,ll> factorization(ll n, const vll &primes)
{
        map<ll,ll> ans;
        for(auto p : primes)
        {
                if (p*p > n) break;
                ll count = 0;
                for (; n%p==0; count++, n/=p);
                if (count)
                        ans[p] = count;
        }
        return ans;
}
