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
  
  // see how much equal segments we have.
  vector<int> r;
  int p = 0;
  int c = 0;
  for(int i = 0; i < (int)a.size(); ++i){
    if(a[i] == a[p]) ++c;
    else{
      if(c > 1) r.emplace_back(c);
      p = i;
      c = 1;
    }
  }
  if(c > 1) r.emplace_back(c);

  // two or more repetitions, impossible to solve.
  if((int)r.size() >= 2) return "NO";
    

  // any repetition longer than two, impossible to solve.
  auto x = max_element(r.begin(), r.end());
  if(x != r.end() and *x > 2) return "NO";
  
  // no error found.
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
