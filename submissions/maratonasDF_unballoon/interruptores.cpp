// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using vi = vector<int>;

vi xs(1e5+1);
int n;

/*
    0: x
    1: x
    2: 0
*/
int main(){ 
  fastio
  cin >> n;
  

  for(int i = 0 ; i < n; ++i) {
    cin >> xs[i];
    xs[i]++;
  }
  
  vector<vi> dp(n, vi(3, 1e5*2));
  dp[0][2] = (xs[0] != 2);
  for(int i = 1; i < n; ++i) {
    auto set0 = dp[i-1][0];
    auto set1 = dp[i-1][1]; 
    auto set2 = dp[i-1][2]; 

    dp[i][0] = min(set0, set1) + (xs[i] != 0);
    dp[i][1] = min(set1, set2) + (xs[i] != 1);
    dp[i][2] = set2 + (xs[i] != 2);
  }

  cout << dp[n-1][0] << '\n';
}

// AC, dp, bottom up
