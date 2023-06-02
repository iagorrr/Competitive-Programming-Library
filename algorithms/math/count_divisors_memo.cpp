const ll mod = 1073741824;
const ll maxd = 100 * 100 * 100 + 1;
vector<ll> memo(maxd, -1);
ll countdivisors(ll x)
{
  ll ox = x;
  ll ans = 1;
  for (ll i = 2; i <= x; ++i)
  {
    if (memo[x] != -1)
    {
      ans *= memo[x];
      break;
    }
    ll count = 0;
    while (x and x % i == 0)
    {
      x /= i;
      count++;
    }
    ans *= (count + 1);
  }
  memo[ox] = ans;
  return ans;
}