const ll MAX = 18;
vll fv(MAX, -1);
ll factorial(ll n) {
        if (fv[n] != -1) return fv[n];
        if (n == 0) return 1;
        return n * factorial(n - 1);
}

template <typename T>
ll permutation_count(vector<T> xs) {
        map<T, ll> h;
        for (auto xi : xs) h[xi]++;
        ll ans = factorial((ll)xs.size());
        dbg(ans);
        for (auto [v, cnt] : h) {
                dbg(cnt);
                ans /= cnt;
        }

        return ans;
}
