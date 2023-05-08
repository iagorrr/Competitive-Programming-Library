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
vector <string> grid;
vector<vll> dp(1e3+1, vll(1e3+1, -1));
int n;
const ll MOD = 1e9+7;
ll solve(ll x, ll y) {

  if(x < 0 or y < 0) return 0;
  if(grid[x][y] == '*') return 0;
  if(dp[x][y] != -1) return dp[x][y];
  
  return dp[x][y] = (solve(x-1, y) + solve(x, y-1)) % MOD;
}

void run(){
  cin >> n; 
  for(int i = 0; i < n; ++i) {
    string s; cin >> s;
    grid.emplace_back(s);
  }

  dp[0][0] = 1;
  cout << solve(n-1, n-1) << '\n';
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}

// AC, dp, top down
