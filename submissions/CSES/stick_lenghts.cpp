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
#define ss second
#define ff first
#define mp make_pair

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

void run(){
  ll n; cin >> n;
  vll xs(n); INV(xs);
  sort(all(xs));
  vll psum(n+1, 0); 
  for(int i = 1; i <= n; ++i)
    psum[i] = psum[i-1] + xs[i-1];
  
  ll ans = LLONG_MAX;
  for(int i = 0; i < n; ++i) {
    ll sumleft = psum[i]; 
    ll sumright = psum[n]-psum[i+1]; 
    ll cost = abs((i)*xs[i]-sumleft) + abs((n-i-1) * xs[i] - sumright); 
    ans = min(ans, cost); 
  }
  cout << ans << '\n';
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}

// AC, prefix sum
