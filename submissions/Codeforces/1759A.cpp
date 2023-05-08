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

int32_t main(void){ fastio;
  int t; cin >> t;
  while(t--) {
    string s; cin >> s;
    string yes ("Yes");
    bool ans = true; 
    if(s.size() == 1 and yes.find(s) == string::npos) ans = false;
    for(int i = 0; i < (int)s.size()-1; ++i) {

      if(yes.find(s[i]) == string::npos){ ans = false; break;}
      else {
        if(s[i] == 'Y' and s[i+1] != 'e') ans= false;
        if(s[i] == 'e' and s[i+1] != 's') ans = false;
        if(s[i] == 's' and s[i+1] != 'Y') ans = false;
      }
    }

    cout << (ans ? "YES" : "NO") << '\n';
  }
}

// AC, strings, implementation.
