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

ll lcm_with_factorization(ll a, ll b) {
        map<ll, ll> fa = factorization(a);
        map<ll, ll> fb = factorization(b);
        ll ans = 1;
        for (auto fai : fa) {
                ll k = max(fai.second, fb[fai.first]);
                while (k--) ans *= fai.first;
        }
        return ans;
}
