// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define INV(aaaa) for(auto &aaaa : aaaaaa) cin >> aaaaa;

#define all(x) x.begin(), x.end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


void run() {
  ll n;
  cin >> n;
  vector<ll> d, e;
  ll ix = 0;
  for (int i = 0; i < n; i++)
  {
    ll t, x;
    cin >> t >> x;
    if (x == 0) d.push_back(t);
    else e.push_back(t);

    if (i == 0) ix = x;
  }

  ll ie = 0, id = 0;
  ll cur = 0;
  while (id < (ll)d.size() and ie < (ll)e.size())
  {
    if (ix == 1 and e[ie] <= cur)
    {
      cur = max(cur, e[ie] + 10);
      ie++;
    }
    else if (ix == 0 and d[id] <= cur)
    {
      cur = max(cur, d[id] + 10);
      id++;
    }
    else
    {
      if (d[id] <= e[ie])
      {
        if (d[id] <= cur)
          cur += 10;
        else
          cur = d[id] + 10;
        id++;
        ix = 0;
      }
      else
      {
        if (e[ie] <= cur)
          cur += 10;
        else
          cur = e[ie] + 10;
        ie++;
        ix = 1;
      }
    }
    cerr << cur << '\n';
  }
  cerr << ie << ' ' << id << ' ' << e.size() << ' ' << d.size() << '\n';
  cerr << cur << '\n';
  if(ie < e.size()) {
      cur = e.back() >= cur ? e.back() + 10 : cur + 10;
  }
  else {
      cur = d.back() >= cur ? d.back() + 10 : cur + 10;
  }
  

  cout << cur << '\n';
}
int32_t main() {
  fastio;
  int t; t =1 ;
  // cin >> t;

  while(t--){
    run();
  }
}
// Implementation.
