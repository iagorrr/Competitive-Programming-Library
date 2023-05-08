// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;

ll solve(ll a, ll b, ll n, ll m) { 
  ll k = n / (m+1ll);
  return min(m*k*a, (m+1ll)*k*b) + min((n-(m+1)*k)*a, (n-(m+1)*k)*b);

}

int32_t main(void){ fastio;
  int t; cin >> t;
  while(t--) {
    ll a,  b; cin >> a >> b;
    ll n, m; cin >> n >> m;
    cout << solve(a, b, n, m) << '\n';
  }
}

// AC.
