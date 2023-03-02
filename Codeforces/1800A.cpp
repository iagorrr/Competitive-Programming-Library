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

string solve(string s, int n) {
  for(int i = 0; i < n; ++i){
    s[i] = tolower(s[i]);
  }
  
  string a;
  for(int i = 0; i < n; ++i){
    if(a.empty() or a.back() != s[i]) a.push_back(s[i]);
  }

  string m = "meow";
  return a == m ? "YES" : "NO";
}
int32_t main(void){ fastio;
  int t; cin >> t;
  while(t--){
    int n; cin>> n;
    string s;
    cin >> s;

    cout << solve(s, n) << '\n';
  }
}
// AC, strings.
