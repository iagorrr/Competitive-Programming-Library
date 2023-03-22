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

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

ll solve(ll a, ll b, ll c, ll d) {
  if(d < b) return -1; 

  ll ans = d - b;
  ll x = a + ans;
  if(x >= c){
    ans += x-c;
    return ans;
  } 
  return -1;

}
void run(){
  ll n;
  cin >> n;
  while(n--) {
    ll a, b, c, d; cin >> a >> b >> c >> d;
    cout << solve(a, b, c, d) << '\n';
  }
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}
// AC, ad-hoc
