map<ll, ll> factorization(ll n) {
        map<ll, ll> ans;
        for (ll i = 2; i * i <= n; i++) {
                ll count = 0;
                for (; n % i == 0; count++, n /= i)
                        ;
                if (count) ans[i] = count;
        }
        if (n > 1) ans[n]++;
        return ans;
}

ll phi(ll n) {
        if (n == 1) return 1;

        auto fs = factorization(n);
        auto res = n;

        for (auto [p, k] : fs) {
                res /= p;
                res *= (p - 1);
        }

        return res;
}

ll fexp(ll a, ll n, ll mod) {
        if (n == 0) return 1;
        if (n == 1) return a;
        ll x = fexp(a, n / 2, mod);
        return x * x * (n & 1 ? a : 1) % mod;
}

ll inv(ll a, ll mod) { return fexp(a, phi(mod) - 1, mod); }
