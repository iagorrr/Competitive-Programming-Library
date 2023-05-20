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
  ll n, m, d; cin >> n >> m >> d;

  vll a(n); INV(a);
  vll b(m); INV(b);
  if(d == 0) {
    set<ll> sta(all(a));
    set<ll> stb(all(b));
    ll ans = -1;
    for(auto v : a) {
      if(stb.count(v)){
        ans = max(ans, v*2);
      }
    }

    cout << ans << '\n';
    return;
  }

  sort(all(a));
  sort(all(b));
  
  // for(auto xi : a) cout << xi << ' '; cout << '\n';
  // for(auto xi : b) cout << xi << ' '; cout << '\n';
  ll ans = -1;
  for(int i = 0; i < n; ++i) {
    ll x = a[i];

    // o menor que consigo até x-d
    // primeiro valor maior que x-d 
    auto left = lower_bound(all(b), x-d);
    if(left == b.end()) left = prev(left);

    // o maior que consigo até x+d
    auto right = lower_bound(all(b), x+d);
    if(right == b.end()) right = prev(right);

    // vai ser um dos dois né porra.
    // cout << "x: " << x << " left: " << *left << " right: "<< *right << '\n';
    if(abs(*left-x) <= d) {
      ans = max(ans, *left+x);
    }
    if(abs(*right-x) <= d) {
      ans = max(ans, *right+x);
    }
  }
  cout << ans << '\n';
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}
// AC, stl, lower bound
