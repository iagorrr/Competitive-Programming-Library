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

string solve(vi a, int n, int s) {
  int c = 0;
  set<int> nec;

  int m = *max_element(a.begin(), a.end());
  for(int i = 1; i <= m; ++i) nec.insert(i);

  for(auto ai : a) {
    nec.erase(ai);
  }
  
  while(!nec.empty()){
    int x = *nec.begin();
    c += x; 
    nec.erase(x);
  }

  m++;
  while(c < s){
    c += m; 
    m++;
  }

  return c == s ? "YES" : "NO";
}

int32_t main(void){ fastio;
  int t; cin >> t;
  while(t--) {
    int n, s; cin >> n >> s;
    vi a(n); INV(a);
    cout << solve(a, n, s) << '\n';
  }
}
// AC.
