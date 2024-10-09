/*8<
  @Title: Binomial MOD
  @Description: find $\binom{n}{k} \pmod{MOD}$
  @Time:
    \begin{compactitem}
      \item precompute: on first call it takes
      $O(MAXNBIN)$ to precompute the factorials
      \item query: $O(1)$.
    \end{compactitem}
  @Memory: $O(MAXNBIN)$
  @Warning: Remember to set $MAXNBIN$ properly !
>8*/
const ll MOD = 998244353;
inline ll binom(ll n, ll k) {
  static const int BINMAX = 2'000'000;
  static vll FAC(BINMAX + 1), FINV(BINMAX + 1);
  static bool done = false;
  if (!done) {
    vll INV(BINMAX + 1);
    FAC[0] = FAC[1] = INV[1] = FINV[0] = FINV[1] = 1;
    for (int i = 2; i <= BINMAX; i++) {
      FAC[i] = FAC[i - 1] * i % MOD;
      INV[i] = MOD - MOD / i * INV[MOD % i] % MOD;
      FINV[i] = FINV[i - 1] * INV[i] % MOD;
    }
    done = true;
  }

  if (n < k || n < 0 || k < 0) return 0;
  return FAC[n] * FINV[k] % MOD * FINV[n - k] % MOD;
}
