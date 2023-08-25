struct Hash {
  const ll P = 31;
  int n;
  string s;
  vll h, hi, p;
  Hash() {}
  Hash(string s) : s(s), n(s.size()), h(n), hi(n), p(n) {
    for (int i = 0; i < n; i++) p[i] = (i ? P * p[i - 1] : 1) % MOD;
    for (int i = 0; i < n; i++) h[i] = (s[i] + (i ? h[i - 1] : 0) * P) % MOD;
    for (int i = n - 1; i >= 0; i--)
      hi[i] = (s[i] + (i + 1 < n ? hi[i + 1] : 0) * P) % MOD;
  }
  ll query(int l, int r) {
    ll hash = (h[r] - (l ? h[l - 1] * p[r - l + 1] % MOD : 0));
    return hash < 0 ? hash + MOD : hash;
  }
  ll query_inv(int l, int r) {
    ll hash = (hi[l] - (r + 1 < n ? hi[r + 1] * p[r - l + 1] % MOD : 0));
    return hash < 0 ? hash + MOD : hash;
  }
};
