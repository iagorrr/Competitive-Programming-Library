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
int edit_distance(const string &a, const string &b) {
  int n = a.size();
  int m = b.size();
  vector<vi> dp(n+1, vi(m+1, 0));

  int ADD=1, DEL=1, CHG=1;
  for(int i = 0; i <= n; ++i) {
    dp[i][0] = i*DEL;
  }
  for(int i = 1; i <= m; ++i) {
    dp[0][i] = ADD*i;
  }

  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= m; ++j) {
      int add = dp[i][j-1]+ ADD;
      int del = dp[i-1][j] + DEL;
      int chg = dp[i-1][j-1] + (a[i-1] == b[j-1] ? 0 : 1)*CHG;
      dp[i][j] = min({add, del, chg});
    }
  }

  return dp[n][m];
}
void run(){
  string a, b; cin >> a >> b;
  cout << edit_distance(a, b) << '\n';
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}
