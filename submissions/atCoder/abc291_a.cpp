// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;
using pll = pair<ll, ll>;
int32_t main(void){ fastio;
  string s; cin >> s;

  for(int i = 0; i < s.size(); ++i) {
    if(toupper(s[i]) == s[i]) {
      cout << i+1 << '\n';
      break;
    }
  }
}
//Ac
