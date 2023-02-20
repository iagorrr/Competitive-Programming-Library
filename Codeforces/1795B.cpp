// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
int32_t main(void){ // fastio;
  int T; cin >> T;

  while(T--){
    int n, k; cin >> n >> k;
    vector<tuple<int, int, int, int>> xs;

    for(int i = 0; i < n; ++i){
      // pass = 0, size, li, ri
      int l, r; cin >> l >> r;

      int pass = 1;
      if(l <= k and r >= k){
        pass = 0;
        xs.emplace_back(pass, r-l, l, r);
      }
    }
    sort(xs.begin(), xs.end());
    string ans = "NO";
    vector<int> psum(50+1, 0);
    for(auto [pass, len, l, r] : xs){
      int curmax = -1;
      for(int i = l; i <= r; ++i){
        psum[i]++;
        if(i != k) curmax = max(curmax, psum[i]);
      }

      if(curmax < psum[k]){
        ans = "YES";
        break;
      }
    }

    cout << ans << '\n';
  }
}

// AC, prefix sum, implementation.
