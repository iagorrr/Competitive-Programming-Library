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

int  solve(string s, int n) {
  int l = 0;
  int r = 2;
  int ans = n-1; // total de ops.
  while(r < n and l < n) {
    if(s[l] == s[r]) ans--;
    l++;
    r++;
  }
  return ans;
}
int32_t main(void){ fastio;
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    string s;
    cin >> s;
    cout << solve(s, n) << '\n';
  }
}

// AC, strings, ad-hoc
