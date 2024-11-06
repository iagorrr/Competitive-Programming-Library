/*8<
  @Title: Factorial Factorization
  @Description: Computes the factorization of $N!$
  in  $\varphi(N)*\log{N}$
  @Time: $O(\varphi(N)\cdot\log{N})$
>8*/
ll E(ll n, ll p) {
    ll k = 0, b = p;
    while (b <= n) {
        k += n / b;
        b *= p;
    }
    return k;
}

map<ll, ll> factorial_factorization(ll n, const vll &primes) {
    map<ll, ll> fs;
    for (const auto &p : primes) {
        if (p > n) break;
        fs[p] = E(n, p);
    }
    return fs;
}
