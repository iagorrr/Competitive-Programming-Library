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

int crosssize(const vector<string> &xs, int x, int y, int h, int w) {
  
  /*
     c  b 
     a  d
  */
  int a = 0;
  while(x+a < h and y-a >= 0 and xs[x+a][y-a] == '#') {
    a++;
  }
  int b = 0;
  while(x-b >= 0 and y+b < w and xs[x-b][y+b] == '#') {
    b++;
  }
  int c = 0;
  while(x-c >= 0 and y-c >= 0 and xs[x-c][y-c] == '#') {
    c++;
  }
  int d = 0;
  while(x+d < h and y+d < w  and xs[x+d][y+d] == '#') {
    d++;
  }
  return min({a, b, c, d});
}

void run(){
  ll h, w; cin >> h >> w;
  vector<string> xs(h); INV(xs);

  map<ll, ll> ans;
  for(int i = 0; i < h; ++i) {
    for(int j = 0; j < w; ++j) {
      auto t = crosssize(xs, i, j, h, w);
      if(t == 1 or t == 0) continue;
      t--;
      ans[t]++;
    }
  }

  for(int i = 1; i <= min(h, w); ++i) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}
