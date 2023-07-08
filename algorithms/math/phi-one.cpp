map<ll, ll> factorization(ll n)
{
        map<ll, ll> ans;
        for (ll i = 2; i*i <= n; i++)
        {
            ll count = 0;
            for (; n%i==0; count++, n/=i);
            if (count)
                      ans[i] = count;
        }
        if (n > 1) ans[n]++;
        return ans;
}

ll phi(ll n)
{
        if (n == 1)
                return 1;

        auto fs = factorization(n);
        auto res = n;

        for (auto [p, k] : fs){
                res /= p;
                res *= (p - 1);
        }

    return res;
}
