ll number_of_divisors(ll n) {
  ll res = 0;

  for (ll d = 1; d * d <= n; ++d) {
    if (n % d == 0) res += (d == n / d ? 1 : 2);
  }

  return res;
}
