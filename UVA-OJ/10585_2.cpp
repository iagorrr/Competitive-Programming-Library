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
  ll n; cin >> n;

  vector<pll> xs;
  for(int i = 0; i < n; ++i) {
    ll x, y; cin >> x >> y;
    xs.emplace_back(x, y);
  }

  sort(all(xs));
  pll s2 = {xs[0].fst+xs[n-1].fst, xs[0].snd+xs[n-1].snd};
  for(int i = 0; i < n ; ++i) {
    pll cur2 = {xs[i].fst+xs[n-i-1].fst, xs[i].snd+xs[n-i-1].snd};
    if(cur2 != s2){
      cout << "no\n";
      return;
    }
  }
  cout << "yes\n";
}
int32_t main(void){ fastio;
  int t; t = 1;
  cin >> t;  
  while(t--)
    run();
}

// AC.
