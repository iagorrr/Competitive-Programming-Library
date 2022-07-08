/*8<
  @Title: Factorization
  @Description: Computes the factorization of N.
  @Time: $O(\sqrt{n})$.
>8*/
map<ll, ll> factorization(ll n) {
    map<ll, ll> ans;
    for (ll i = 2; i * i <= n; i++) {
        ll count = 0;
        for (; n % i == 0; count++, n /= i);
        if (count) ans[i] = count;
    }
    if (n > 1) ans[n]++;
    return ans;
}
