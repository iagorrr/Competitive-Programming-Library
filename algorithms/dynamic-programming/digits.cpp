ll memo[19][10][2];
ll dp(int p, int d, bool l, const vi &digits) {
  if (p == len(digits)) return 0;

  if (memo[p][d][l] != -1) return memo[p][d][l];

  ll tot = 0;
  ll k = l and d == digits[p] ? digits[p + 1] : 9;
  for (int i = 0; i <= k; i++) {
    if (i == 4) continue;
    if (d == 1 and i == 3) continue;
    tot += dp(p + 1, i, l and d == digits[p], digits);
  }

  return memo[p][d][l] = tot;
}

vi get_digits(ll x) {
  vi digits;

  while (x) {
    digits.emplace_back(x % 10);
    x /= 10;
  }

  reverse(all(digits));
  return digits;
}

ll dp(ll x) {
  auto digits = get_digits(x);
  memset(memo, -1, sizeof memo);

  dbg(x, len(digits) - 1, digits);
  for (int i = 0; i <= 9; i++) {
    memo[len(digits) - 1][i][0] = 1;
    memo[len(digits) - 1][i][1] = i <= digits.back();
  }

  ll tot = 0;
  for (int i = 0; i <= digits[0]; i++) {
    if (i == 4) continue;
    tot += dp(0, i, i == digits[0], digits);
  }

  return tot - 1;
}
