int phi(int n) {
  if (n == 1) return 1;

  auto fs = factorization(n);  // a vctor of pair or a map
  auto res = n;

  for (auto [p, k] : fs) {
    res /= p;
    res *= (p - 1);
  }

  return res;
}
