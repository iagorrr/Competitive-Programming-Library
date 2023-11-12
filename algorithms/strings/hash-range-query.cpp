struct Hash {
  const ll P = 31;
  const ll mod = 1e9 + 7;
  string s;
  int n;
  vll h, hi, p;
  Hash() {}
  Hash(string s) : s(s), n(s.size()), h(n), hi(n), p(n) {
    for (int i = 0; i < n; i++)
      p[i] = (i ? P * p[i - 1] : 1) % mod;
    for (int i = 0; i < n; i++)
      h[i] = (s[i] + (i ? h[i - 1] : 0) * P) % mod;
    for (int i = n - 1; i >= 0; i--)
      hi[i] =
        (s[i] + (i + 1 < n ? hi[i + 1] : 0) * P) % mod;
  }
  ll query(int l, int r) {
    ll hash =
      (h[r] - (l ? h[l - 1] * p[r - l + 1] % mod : 0));
    return hash < 0 ? hash + mod : hash;
  }
  ll query_inv(int l, int r) {
    ll hash =
      (hi[l] -
       (r + 1 < n ? hi[r + 1] * p[r - l + 1] % mod : 0));
    return hash < 0 ? hash + mod : hash;
  }
};
