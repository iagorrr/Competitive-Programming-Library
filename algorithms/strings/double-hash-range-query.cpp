const ll MOD = 1000027957;
const int MOD2 = 1000015187;

struct Hash {
  const ll P = 31;
  int n;
  string s;
  vll h, h2, hi, hi2, p, p2;
  Hash() {}
  Hash(string _s) : s(_s), n(len(_s)), h(n), h2(n), hi(n), hi2(n), p(n), p2(n) {
    for (int i = 0; i < n; i++) p[i] = (i ? P * p[i - 1] : 1) % MOD;
    for (int i = 0; i < n; i++) p2[i] = (i ? P * p2[i - 1] : 1) % MOD2;
    for (int i = 0; i < n; i++) h[i] = (s[i] + (i ? h[i - 1] : 0) * P) % MOD;
    for (int i = 0; i < n; i++) h2[i] = (s[i] + (i ? h2[i - 1] : 0) * P) % MOD2;
    for (int i = n - 1; i >= 0; i--)
      hi[i] = (s[i] + (i + 1 < n ? hi[i + 1] : 0) * P) % MOD;
    for (int i = n - 1; i >= 0; i--)
      hi2[i] = (s[i] + (i + 1 < n ? hi2[i + 1] : 0) * P) % MOD2;
  }
  pii query(int l, int r) {
    ll hash = (h[r] - (l ? h[l - 1] * p[r - l + 1] % MOD : 0));
    ll hash2 = (h2[r] - (l ? h2[l - 1] * p2[r - l + 1] % MOD2 : 0));

    return {(hash < 0 ? hash + MOD : hash), (hash2 < 0 ? hash2 + MOD2 : hash2)};
  }
  pii query_inv(int l, int r) {
    ll hash = (hi[l] - (r + 1 < n ? hi[r + 1] * p[r - l + 1] % MOD : 0));
    ll hash2 = (hi2[l] - (r + 1 < n ? hi2[r + 1] * p2[r - l + 1] % MOD2 : 0));
    return {(hash < 0 ? hash + MOD : hash), (hash2 < 0 ? hash2 + MOD2 : hash2)};
  }
};
