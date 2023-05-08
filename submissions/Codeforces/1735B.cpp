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

int needdiv(int x, int y) {
  return x/(y*2-1) + (x%(y*2-1) ? 1 : 0) - 1;
}
int solve(map<ll, ll> cnt) {
  int ans = 0;
  int lower = (*cnt.begin()).first;

  for(auto [v, q] : cnt) {
    if(lower*2 <= v) {
      int k = needdiv(v,  lower) * q;
      ans += k; 
    }
  }
  return ans;
}
int32_t main(void){ fastio;
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    map<ll, ll> cnt;
    for(int i = 0; i < n; ++i){
      int x; cin >> x;
      cnt[x]++;
    }
    cout << solve(cnt) << '\n';
  }
}

// AC, math.
