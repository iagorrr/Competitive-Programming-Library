// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define INV(a) for(auto &x : a) cin >> x;
using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;
using pll = pair<ll, ll>;

ll solve(const vi &a, ll n){
  vll count(n*2+1);
  ll cur = 0;
  count[cur]++;
  ll ans = 0;
  for(auto x : a){
    cur = cur^x;
    
    for(long long i = 0ll; i*i < n*2; ++i) {
      ans += ((i*i) ^ cur) < 2*n ? count[((i*i) ^ cur)] : 0ll;
    }
    count[cur]++;
  }

  return (n * (n+1ll) / 2ll) - ans;
}
int32_t main(void){ fastio;
  int t; cin >> t;
  while(t--) {
    ll n; cin >> n;
    vi a(n);  INV(a);
    cout << solve(a, n) << '\n';
  }
}

// AC.
