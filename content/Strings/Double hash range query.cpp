using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;

const int MAXN(1 '000' 000);
const ll MOD = 1000027957;
const ll MOD2 = 1000015187;
const ll P = 31;

ll p[MAXN + 1], p2[MAXN + 1];
void precompute() {
  p[0] = p2[0] = 1;
  for (int i = 1; i <= MAXN; i++)
    p[i] = (P * p[i - 1]) % MOD, p2[i] = (P * p2[i - 1]) % MOD2;
}

struct Hash {
  int n;
  vll h, h2, hi, hi2;
  Hash() {}
  Hash(const string &s) : n(s.size()), h(n), h2(n), hi(n), hi2(n) {
    h[0] = h2[0] = s[0];
    for (int i = 1; i < n; i++)
      h[i] = (s[i] + h[i - 1] * P) % MOD, h2[i] = (s[i] + h2[i - 1] * P) % MOD2;

    hi[n - 1] = hi2[n - 1] = s[n - 1];
    for (int i = n - 2; i >= 0; i--)
      hi[i] = (s[i] + hi[i + 1] * P) % MOD,
      hi2[i] = (s[i] + hi2[i + 1] * P) % MOD2;
  }
  pll query(int l, int r) {
    ll hash = (h[r] - (l ? h[l - 1] * p[r - l + 1] % MOD : 0));
    ll hash2 = (h2[r] - (l ? h2[l - 1] * p2[r - l + 1] % MOD2 : 0));

    return {(hash < 0 ? hash + MOD : hash), (hash2 < 0 ? hash2 + MOD2 : hash2)};
  }
  pll query_inv(int l, int r) {
    ll hash = (hi[l] - (r + 1 < n ? hi[r + 1] * p[r - l + 1] % MOD : 0));
    ll hash2 = (hi2[l] - (r + 1 < n ? hi2[r + 1] * p2[r - l + 1] % MOD2 : 0));
    return {(hash < 0 ? hash + MOD : hash), (hash2 < 0 ? hash2 + MOD2 : hash2)};
  }
};
