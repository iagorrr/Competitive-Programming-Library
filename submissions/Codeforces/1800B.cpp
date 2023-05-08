// iagorrr ;)
#include <bits/stdc++.h>
#include <cctype>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
#define INV(a) for(auto &x : a) cin >> x
#define all(a) a.begin(), a.end()

int solve(string s, int n, int k){
  map<char, int> h;
  int ans = 0;
  for(auto c : s){
    if(islower(c)) {
      if(h[toupper(c)] >= 1){
        ans++;
        h[toupper(c)]--;
      }
      else h[c]++;
    }
    else{
      if(h[tolower(c)] >= 1) {
        ans++;
        h[tolower(c)]--;
      }
      else h[c]++;
    }
  }

  for(char c = 'a'; c <= 'z'; c++){
    if(k == 0) break;
    if(h[c] > 1) {
      int increase = min(k, h[c]/2);
      ans += increase; 
      k -= increase;
    }
    if(h[toupper(c)]) {
      int increase = min(k, h[toupper(c)]/2);
      ans += increase;
      k -= increase;
    }
  }
  return ans;
}

int32_t main(void){ fastio;
  int t; cin >> t;
  while(t--) {
    int n, k; cin >> n >> k;
    string s;
    cin >> s;
    cout << solve(s, n, k) << '\n';
  }
}

// AC, string, histogram.
