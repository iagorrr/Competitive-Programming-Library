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
  set<pll> pts(all(xs));
  int i = 0;
  // cout << "\n\n0: " << xs[0].fst << ' ' << xs[0].snd << '\n';
  for(int j = 0; j < n; ++j) {
    pll s2 = {(xs[i].fst)+(xs[j].fst), (xs[i].snd)+(xs[j].snd)};
    // cout << "\n\ns2: " << s2.fst << ' ' << s2.snd << '\n';
    bool todos = true;
    for(int k = 0; k < n; ++k) {
      /*
        s2 = k + p
        -p + s2 = k
        -p = k - s2
        p = s2-k
      */
      pll p = {(s2.fst)-(xs[k].fst), (s2.snd)-(xs[k].snd)};
      // cout << "p: " << p.fst << ' ' << p.snd << '\n';
      // cout << "k: " << xs[k].fst << ' ' << xs[k].snd << '\n';
      if(! pts.count(p)) {
        todos = false;
        break;
      }
    }
    if(todos){
      cout << "yes\n";
      return;
    }
  }
  cout << "no\n";
}
int32_t main(void){ fastio;
  int t; t = 1;
  cin >> t;  
  while(t--)
    run();
}

// AC.
