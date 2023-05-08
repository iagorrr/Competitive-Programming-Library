// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
#define INV(xxxx)        \
  for (auto &xxx : xxxx) \
    cin >> xxx;
#define all(a) a.begin(), a.end()
#define ss second
#define ff first
#define mp make_pair

void dbg_out()
{
  cerr << endl;
}
template <typename H, typename... T>
void dbg_out(H h, T... t)
{
  cerr << ' ' << h;
  dbg_out(t...);
}
#define dbg(...)                 \
  {                              \
    cerr << #__VA_ARGS__ << ':'; \
    dbg_out(__VA_ARGS__);        \
  }

void run()
{
  int n, m;
  cin >> n >> m;
  vi xs(n);
  INV(xs);

  const int mod = 1e9 + 7;
  /*
     for each position i which possibilities
     mantain if i put j there.
  */
  vector<vector<int>> dp(n, vector<int>(m + 1, 0));

  // if the firxt is fixed there is a single poss.
  if (xs[0])
  {
    dp[0][xs[0]] = 1;
  }
  else
  { // i can put whatever number there.
    fill(dp[0].begin(), dp[0].end(), 1);
  }

  for (int i = 1; i < n; ++i)
  {
    /*
       when a value is fixed, that means
       i can only carry the possibilities
       that this value allows.
    */
    if (xs[i])
    {
      dp[i][xs[i]] += dp[i - 1][xs[i]];
      if (xs[i] - 1 >= 1)
        dp[i][xs[i]] += dp[i - 1][xs[i] - 1];
      if (xs[i] + 1 <= m)
        dp[i][xs[i]] += dp[i - 1][xs[i] + 1];
      dp[i][xs[i]] %= mod;
    }
    else
    {
      for (int j = 1; j <= m; ++j)
      {
        dp[i][j] += dp[i - 1][j];
        if (j -1 >= 1)
          dp[i][j] += dp[i - 1][j - 1];
        if (j + 1 <= m)
          dp[i][j] += dp[i - 1][j + 1];
        dp[i][j] %= mod;
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= m; ++i)
  {
    ans = (ans + dp[n - 1][i]) % mod;
  }

  cout << ans << '\n';
}
int32_t main(void)
{
  // fastio;
  int t;
  t = 1;

  while (t--)
    run();
}
