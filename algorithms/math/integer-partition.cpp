const ll MOD = 1000000007;
const int MAXN(100);
ll memo[MAXN + 1];
ll dp(ll n, ll k = oo) {
  if (n == 0) return 1;
  ll &ans = memo[n];
  if (ans != -1) return ans;

  ans = 0;
  for (int i = 1; i <= min(n, k); i++) {
    ans = (ans + dp(n - i, k)) % MOD;
  }

  return ans;
}
