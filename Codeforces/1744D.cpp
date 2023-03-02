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

int solve(vi a, int  n){ 
  vector<pii> bs;
  int tot2n = 0;
  for(int i = 0; i < n; ++i) {
    int index = 0;
    int i2 = i+1;
    while(i2%2 == 0 and i > 0) {
      index++;
      i2 /= 2;
    }

    int value = 0;
    while(a[i]%2 == 0 and a[i] > 0){
      a[i] /= 2;
      value++;
    }
    tot2n += value;
    bs.emplace_back(index, value); 
  }
  
  int ans = 0;
  sort(bs.begin(), bs.end());
  while(tot2n < n and !bs.empty()) {
    tot2n += bs.back().first; 
    bs.pop_back();
    ans++;
  }

  
  return tot2n >= n ? ans : -1;
}
int32_t main(void){ fastio;
  int t; cin >> t;

  while(t--){
    int n; cin >> n;

    vector<int> a(n); INV(a); 
    
    cout << solve(a, n) << '\n';
  }
}

// AC.
