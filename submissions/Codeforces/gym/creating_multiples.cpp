#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define INV(aaaa) for(auto &aaaa : aaaaaa) cin >> aaaaa;

#define all(x) x.begin(), x.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

ll fpow(ll x, ll p, ll m = 1e9+7)
{
  if (p == 0)
    return 1;
  ll ans = fpow(x, p >> 1, m);
  ans = (ans * ans) % m;
  if (p & 1) ans = (ans * x) % m;
  return ans;
}

void run() {
  ll b, n;
  cin >> b >> n;
  vector<ll> v(n);
  for (auto &x : v) cin >> x;

  ll mod_atual = 0;
  for (int i = 0; i < n; ++i)
    mod_atual = (mod_atual + v[i] * fpow(b, n-1-i, b+1)) % (b+1);

  if (mod_atual == 0)
  {
    cout << "0 0\n";
    return;
  }

  for (int i = 0; i < n; i++)
  {
    if ((i + n) & 1)
    {
      if (v[i] >= mod_atual)
      {
        cout << i + 1 << ' ' << v[i] - mod_atual << '\n';
        return;
      }
    }
    else
    {
      if (v[i] >= b+1 - mod_atual)
      {
        cout << i + 1 << ' ' << v[i] - (b+1 - mod_atual) << '\n';
        return;
      }
    }
  }

  cout << "-1 -1\n";
}

int32_t main() {
  fastio;
  int t; t =1 ;
  // cin >> t;

  while(t--){
    run();
  }
}

// AC, math
