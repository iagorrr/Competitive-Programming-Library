// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;
using pll = pair<ll, ll>;
string solve(string s, int n) {
  int l = 0;
  int r = n-1;
  bool started = false;
  bool closed = false;

  while(l < r) {
    if(s[l] != s[r]){  
      started = true;
      if(closed) return "No";
    }
    else {
      if(started) {
        started = false;
        closed = true;
      }
    }
    l++;
    r--;
  }

  return "Yes";
}
int32_t main(void){ fastio;
  int t;  cin >> t;
  while(t--) {
    int n; cin >> n;
    string s; cin >> s;

    cout << solve(s, n) << '\n';
  }
}
// strings.
