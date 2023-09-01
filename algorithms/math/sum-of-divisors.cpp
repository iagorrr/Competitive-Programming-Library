ll sum_of_divisors(long long n) {
  ll res = 0;

  for (ll d = 1; d * d <= n; ++d) {
    if (n % d == 0) {
      ll k = n / d;

      res += (d == k ? d : d + k);
    }
  }

  return res;
}
