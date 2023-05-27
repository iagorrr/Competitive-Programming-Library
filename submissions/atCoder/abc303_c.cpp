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

// estritamentte menor que k, consume e vira k
// ver se consegue completar.
// perde no negativos
set<pll> items;
void run(){
  ll n, m, h, k; cin >> n >> m >> h >> k; 
  string s;
  cin >> s;
  for(int i = 0; i < m; ++i) {
    ll x, y;
    cin >>x >> y;
    items.insert({x, y});
  }

  ll x, y; x = y = 0;
  map<char, pll> moves({
      {'R', {1, 0}},
      {'L', {-1, 0}},
      {'D', {0, -1}},
      {'U', {0, 1}}}
  );

  for(auto move : s){

    h--; 
    
    if(h<0) {
      cout << "No\n";
      return;
    }

    x += moves[move].first;
    y += moves[move].second;
    
    if(items.count({x, y})){
      if(h < k){
         h = k;
         items.erase({x, y});
      }
    }
  }

  cout << "Yes\n";
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}
// AC, implementation.
