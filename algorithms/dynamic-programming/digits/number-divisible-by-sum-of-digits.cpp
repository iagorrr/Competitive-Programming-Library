const int P10(14);
string K;
ll D;
vi digits;
ll _dp[P10 + 1][9 * P10][9 * P10][2];
ll dp(int pos = 0, int rest = 0, int cursum = 0,
      bool lim = 1) {
  if (pos == len(digits)) return rest == 0 and cursum == D;

  ll &ans = _dp[pos][rest][cursum][lim];

  if (ans != -1) {
    return ans;
  }

  ans = 0;
  int maxi = lim ? digits[pos] : 9;
  for (int i = 0; i <= maxi; i++) {
    ans += dp(pos + 1, (rest * 10 + i) % D, cursum + i,
              lim & (i == maxi));
  }

  return ans;
}

ll solve(const string &k) {
  digits.clear();
  for (auto c : k) digits.emplace_back(c - '0');

  ll ans = 0;
  for (int i = 1; i <= P10 * 9; i++) {
    memset(_dp, -1, sizeof _dp);
    D = i;
    ans += dp();
  }

  return ans;
}
