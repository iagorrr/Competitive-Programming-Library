vi digits;
ll DP[18 + 1][10][2][2];
ll call(int pos = 0, int prev = 0, bool lim = true,
        bool only0 = true) {
  if (pos == len(digits)) return 1;

  ll &ans = DP[pos][prev][lim][only0];

  if (ans != -1) {
    return DP[pos][prev][lim][only0];
  }

  ans = 0;
  int maxi = lim ? digits[pos] : 9;
  for (int i = 0; i <= maxi; i++) {
    if (i == prev and !(!prev and !i and only0)) continue;
    ans +=
      call(pos + 1, i, lim and i == maxi, only0 & (i == 0));
  }

  return ans;
}

ll solve(ll x) {
  memset(DP, -1, sizeof DP);
  digits.clear();
  while (x) digits.emplace_back(x % 10), x /= 10;
  reverse(all(digits));
  return call();
}
