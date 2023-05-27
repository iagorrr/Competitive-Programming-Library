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

vector<vector<ll>> xxx(50, vll(50));
int n, m;
bool check(ll x, ll y) {
  for(int i = 0; i < m; ++i) {
    for(int j = 0; j < n-1; ++j) {
      if(xxx[i][j] == x and xxx[i][j+1] == y) return true;
      if(xxx[i][j] == y and xxx[i][j+1] == x) return true;
    }
  }
  return false;
}
void run(){
   cin >> n >> m;

  for(int i = 0; i < m; ++i) {
    for(int j = 0; j < n; ++j) {
      cin >> xxx[i][j];
    }
  }


  set<pll> ans;
  for(int i = 1; i <= n; ++i) {

    for(int j = i+1; j <= n; ++j) {
      if(!check(i, j)){
        ans.insert({min(i, j), max(i,j)});
      }
    }
  }

  cout << ans.size() << '\n';
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}

// AC, implementation
