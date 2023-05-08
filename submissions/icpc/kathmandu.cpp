// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define INV(aaaa) for(auto &aaaa : aaaaaa) cin >> aaaaa;

#define all(x) x.begin(), x.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


void run() {
  ll t, d, m;
  cin >> t >> d >> m;
  ll cur = 0;
  char ans = 'N';
  for (int i = 0; ans == 'N' and i < m; i++)
  {
    ll x;
    cin >> x;
    if (t <= x - cur)
      ans = 'Y';
    cur = x;
  }
  if (d - cur >= t)
    ans = 'Y';
  cout << ans << '\n';
}
int32_t main() {
  fastio;
  int t; t =1 ;
  // cin >> t;

  while(t--){
    run();
  }
}

// AC, implementation.
