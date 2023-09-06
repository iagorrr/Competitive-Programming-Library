const ll MOD = 1e9 + 7;
const ll maxn = 2 * 1e6;
vll fats(maxn + 1, -1);
void precompute() {
  fats[0] = 1;
  for (ll i = 1; i <= maxn; i++) {
    fats[i] = (fats[i - 1] * i) % MOD;
  }
}

ll fpow(ll a, ll n, ll mod = LLONG_MAX) {
  if (n == 0ll) return 1ll;
  if (n == 1ll) return a;
  ll x = fpow(a, n / 2ll, mod) % mod;
  return ((x * x) % mod * (n & 1ll ? a : 1ll)) % mod;
}

ll binommod(ll n, ll k) {
  ll upper = fats[n];
  ll lower = (fats[k] * fats[n - k]) % MOD;
  return (upper * fpow(lower, MOD - 2ll, MOD)) % MOD;
}
