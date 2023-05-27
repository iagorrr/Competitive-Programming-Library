// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
#define INV(xxxx) for(auto &xxx : xxxx) cin >> xxx;
#define all(a) a.begin(), a.end()
#define snd second
#define fst first

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }
void run(){

  ll x, y, z; cin >> x >> y >> z;
  string s; cin >> s;
  vector<vll> ans(2, vll(s.size()+10, 0));
  /*
     0 - caps off
     1 - caps on
     x - press key
     y - key + shift
     z - press caps 
  */
  ans[1][0] = z;
  for(int i = 0; i < (int)s.size(); ++i) {
    ll p = i+1;
    if(s[i] == 'A'){
      ans[1][p] = min(ans[1][p-1] + x, ans[0][p-1]+z+x); // ok
      ans[0][p] = min(ans[0][p-1] + y, ans[1][p-1]+z+y); 
    }
    else {
      ans[1][p] = min(ans[1][p-1] + y, ans[0][p-1]+z+y);
      ans[0][p] = min(ans[0][p-1]+x, ans[1][p-1]+x+z);
    }
  }

  cout << min(ans[1][s.size()], ans[0][s.size()]) << '\n';
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}

// AC, dp, bottom up
