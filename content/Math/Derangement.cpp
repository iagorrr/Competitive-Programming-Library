/*8<
  @Title: Derangement / Matching Problem

  @Description:
    Computes the derangement of $N$, which is
    given by the formula:
      $D_N = N! \left(1 - \frac{1}{1!} +
      \frac{1}{2!} - \frac{1}{3!} + \ldots +
      (-1)^N \frac{1}{N!}\right)$

  @Time: $O(N)$
>8*/
#warning Remember to call precompute !
const ll MOD = 1e9 + 7;
const int MAXN(1 '000' 000);
ll fats[MAXN + 1];
void precompute() {
    fats[0] = 1;
    for (ll i = 1; i <= MAXN; i++) {
        fats[i] = (fats[i - 1] * i) % MOD;
    }
}

ll fastpow(ll a, ll p, ll m) {
    ll ret = 1;
    while (p) {
        if (p & 1) ret = (ret * a) % MOD;
        p >>= 1;
        a = (a * a) % MOD;
    }
    return ret;
}

ll divmod(ll a, ll b) { return (a * fastpow(b, MOD - 2, MOD)) % MOD; }

ll derangement(const ll n) {
    ll ans = fats[n];
    for (ll i = 1; i <= n; i++) {
        ll k = divmod(fats[n], fats[i]);
        if (i & 1) {
            ans = (ans - k + MOD) % MOD;
        } else {
            ans = (ans + k) % MOD;
        }
    }
    return ans;
}
