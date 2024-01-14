const int MAXD(100), MAXKLEN(10000);
string K;
ll D;
vi digits;
ll _dp[MAXKLEN + 1][MAXD][2];
const ll MOD(1'000'000'007);
ll dp(int pos = 0, int md = 0, bool lim = 1) {
  if (pos == len(digits)) return md == 0;

  ll &ans = _dp[pos][md][lim];

  if (ans != -1) {
    return ans;
  }

  ans = 0;
  int maxi = lim ? digits[pos] : 9;
  for (int i = 0; i <= maxi; i++) {
    int mdn = (md + i) % D;
    ans = (ans + dp(pos + 1, mdn, lim & (i == maxi))) % MOD;
  }

  return ans;
}

ll solve(string x) {
  digits.clear();
  for (auto c : x) digits.emplace_back(c - '0');
  memset(_dp, -1, sizeof _dp);
  return dp();
}
