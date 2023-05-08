// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;
using pll = pair<ll, ll>;
#define INV(a) for(auto &x : a) cin >> x
#define all(a) a.begin(), a.end()

void solve(const vi &a, int n) {
  set<int> s(all(a));
  int l = 0;
  int r = n-1;
  while(l < r) {
    if( (a[l] != *s.begin() and a[l] != *prev(s.end()) ) and  (a[r] != *s.begin() and a[r] != *prev(s.end()) ) ){
      cout << l+1 << ' ' << r+1 << '\n';
      return;
    }
    if(a[l] == *s.begin() or a[l] == *prev(s.end())) s.erase(a[l]), l++;
    if(a[r] == *s.begin() or a[r] == *prev(s.end())) s.erase(a[r]), r--;
  }
  cout << "-1\n";
}
int32_t main(void){ fastio;
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vi a(n); INV(a);
    solve(a, n);
  }
}

// AC, two pointers, set.
