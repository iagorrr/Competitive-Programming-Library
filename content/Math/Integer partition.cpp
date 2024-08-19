/*8<
  @Title: Integer partition
  @Description:
    Find the total of ways to partition a given
    number $N$ in such way that none of the parts
    is greater than $K$.
  @Time: $O(N \cdot min(N, K))$
  @Memory: $O(N)$
  @Warning:
    Remember to memset everything to $-1$ before
    using it


>8*/
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
