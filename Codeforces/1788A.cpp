// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
#define minpq  priority_queue<ll, vll, greater<ll>()>
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)

int solve(vector<int> a, int n){
  vector<int> psum(n+1, 0);
  for(int i = 1; i <= n; ++i){
    psum[i] = psum[i-1] + (a[i-1] == 2);
  }

  for(int i = 1; i < n; ++i){
    if(psum[i] == psum[n]-psum[i]) return i;
  }

  return -1;
}

int32_t main(void){ fastio;
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    vector<int> a(n); for(auto &x: a) cin >> x;

    cout << solve(a, n) << '\n';
  }
}

// AC, prefix sum
