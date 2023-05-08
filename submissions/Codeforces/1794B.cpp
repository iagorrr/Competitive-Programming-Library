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

void solve(vll a, int n) {
  // there can't be any number 1. (it will always divide the successor)
  for(int i = 0; i < n; ++i)
    if(a[i] == 1) a[i]++;
  
  // necessary to increase the numerator cause the denominator may keep being a divisor after increase 1.
  for(int i = 0; i < n-1; ++i)
    if(a[i+1]%a[i] == 0) a[i+1]++;

  for(int i = 0; i < n; ++i)
    cout << a[i] << " \n"[i==n-1];
}
int32_t main(void){ fastio;
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vll a(n); INV(a);
    solve(a, n);
  }
}

// AC, math, number theory
