// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;
using pll = pair<ll, ll>;
string solve(vll a, int n) {
  for(int i = 0; i < n; ++i) {
    for(int j = i+1; j < n; ++j) {
      if(__gcd(a[i], a[j]) <= 2) return "Yes";
    }
  }
  return "No";
}
int32_t main(void){ fastio;
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vll a(n); for(auto &x : a) cin >> x;
    cout << solve(a, n) << '\n';
  }
}
// AC.
