// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;
using pll = pair<ll, ll>;
int32_t main(void){ fastio;
  int n; cin >> n;
  vi a(n*5); for(auto &x : a) cin >> x;
  sort(a.begin(), a.end());
  ll ans = accumulate(a.begin()+n, a.begin()+n*4, 0);
  cout.precision(18);
  cout << (double)ans/((double)3*(double)n) << '\n';
}

// AC.
