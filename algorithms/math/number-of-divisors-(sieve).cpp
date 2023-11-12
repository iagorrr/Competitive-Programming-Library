ll divisors(ll n) {
  ll ans = 1;
  for (auto p : primes) {
    if (p * p * p > n) break;

    int count = 1;
    while (n % p == 0) {
      n /= p;
      count++;
    }

    ans *= count;
  }

  if (is_prime[n])
    ans *= 2;
  else if (is_prime_square[n])
    ans *= 3;
  else if (n != 1)
    ans *= 4;

  return ans;
}
