// calculates K^0 + K^1 ... + K^n
ll fastpow(ll a, int n) {
        if (n == 1) return a;
        ll x = fastpow(a, n / 2);
        return x * x * (n & 1 ? a : 1);
}
ll powersum(ll n, ll k) { return (fastpow(n, k + 1) - 1) / (n - 1); }
