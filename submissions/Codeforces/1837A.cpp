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
  ll x, k; cin >> x >> k;

  if(x%k != 0){
    cout << 1 << '\n';
    cout << x << '\n';
    return;
  }
  for(ll i = 1; i < x; ++i) {
    if(i%k != 0 and (x-i)%k != 0){
        cout << 2 << '\n';
        cout << i << ' ' << (x-i) << '\n';
      return;
    }
  }
}
int32_t main(void){ fastio;
  int t; t = 1;
  cin >> t;  
  while(t--)
    run();
}
// AC, ad-hoc
