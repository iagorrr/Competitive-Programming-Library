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

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

void run(){
  ll n; cin >> n;
  string s; cin >> s; 
  ll best = -1; 
  ll k = 0;
  while(k < n and s[k] == s[0]) ++k;

  for(int i = k; i < n; ++i) {
    if(best == -1 and s[i] <= s[0]) best = i;
    else if((s[i] <= s[0] and (s[i] <= s[best]))) best = i;
  }



  if(best == -1) cout << s << '\n';
  else{
    cout << s[best];
    for(int i = 0; i < s.size(); ++i) {
      if(i != best) cout << s[i];
    }
    cout << '\n';
  }
}
int32_t main(void){ //fastio;
  int t; t = 1;
  cin >> t; 
  while(t--)
    run();
}

// AC, strings, ad-hoc.
