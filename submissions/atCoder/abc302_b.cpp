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

ll h, w;
vector<string> grid(1e5+1);

int dx[] {0, 0, 1, -1, 1, -1, 1, -1};
int dy[] {1, -1, 0, 0, -1, 1, 1, -1};
string goal = "snuke";
vector<pll> check(int x, int y, int ddx, int ddy) {
  vector<pll> ans;
  int i = 0;
  while(i < 5) {
    if(x >= 0 and x < h and y >= 0 and y < w
        and grid[x][y] == goal[i])
      ans.push_back({x, y});

    x += ddx;
    y += ddy;
    ++i;
  }
  vector<pll> aux;
  return ans.size() == 5 ? ans : aux;
}

void run(){
 cin >> h >> w;
 for(int i = 0; i < h; ++i)
   cin >> grid[i];
 
 for(int i = 0; i < h; ++i) {
    for(int j = 0; j < w; ++j) {
      for(int k = 0; k < 8; ++k) {
        auto ans = check(i, j, dx[k], dy[k]);
        if(!ans.empty()) {
          for(auto [a, b] : ans) {
            cout << a+1 << ' ' << b+1 << '\n';
          }
          return;
        }
      }
    }
 } 
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}

// AC, implementation.
