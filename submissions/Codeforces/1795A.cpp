// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;

string solve(string s, string t){
  reverse(t.begin(), t.end());
  string a; 
  a = s + t;
  int cont = 0;
  for(int i = 0; i < (int)a.size()-1; ++i){
    if(a[i] == a[i+1]) cont++;
    if(cont > 1) return "NO";
  }
  return "YES";
}
int32_t main(void){
  int t; cin >> t;
  while(t--){
    int n, m; cin >> n >> m;
    string s, p; cin >> s >> p;
    cout << solve(s, p) << '\n';
  }
}

// AC, ad-hoc.
