// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
#define INV(a) for(auto &x : a) cin >> x
#define all(a) a.begin(), a.end()

int ways(int n)
{
    int total = 1;
    for (int p = 2; p*p <= n; p++) {
      int count = 0;
      if (n % p == 0) {
          while (n % p == 0) {
              n = n / p;
              count++;
          }
          total = total * (count + 1);
      }
    }
    if(n > 1) total *= 2; 
    return total;
}

ll solve(ll n) {
  ll ans = 0;
  for(ll ab = 1; ab <= n-1; ++ab) {
    ans += ways(ab)*ways(n-ab);
  }
  return ans;
}

int32_t main(void){ fastio;
  ll n; cin >> n;
  cout << solve(n) << '\n';
}

// AC, math, number theory.
