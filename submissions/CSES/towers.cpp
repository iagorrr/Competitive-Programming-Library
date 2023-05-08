// iagorrr ;)
#include <bits/stdc++.h>
#include <cmath>
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
  vll xs(n);
  for(int i = 0; i < n; ++i) cin >> xs[i];
  multiset<ll> top;
  for(int i = 0; i < n; ++i) {
    auto pos = top.lower_bound(xs[i]);

    if(top.empty()) {
      top.insert(xs[i]);
      continue;
    }
    if(pos == top.begin()){
      if(*pos > xs[i]){
        top.erase(pos);
      }
      top.insert(xs[i]);
    }
    else if (pos == top.end()) {
      if(*prev(pos) > xs[i]) {
        top.erase(prev(top.end()));
      }
      top.insert(xs[i]);
    }
  }

  cout << top.size() << '\n';
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}
