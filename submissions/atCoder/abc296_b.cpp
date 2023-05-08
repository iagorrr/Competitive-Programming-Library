// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
#define INV(a) for(auto &x : a) cin >> x
#define all(a) a.begin(), a.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

void bomb(vector<string> &b, int i, int j, int r, int c, int ml) {
  if(ml == 0) return;

  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, -1, 1};

  for(int k = 0; k < 4; ++k) {
    int i2 = i + dx[k];
    int j2 = j + dy[k];
    if(i2 >= 0 and i2 < r and j2 >= 0 and j2 < c) {
      bomb(b, i2, j2, r, c, ml-1);
      if(b[i2][j2] > '9' or b[i2][j2] < '1') b[i2][j2] = '.';
    }
  }
}
void solve(vector<string> b, int r, int c) {
  for(int i = 0 ; i < r; ++i) {
    for(int j = 0; j < c; ++j) {
      if(b[i][j] >= '1' and b[i][j] <= '9') {
        bomb(b, i, j, r, c, b[i][j]-'0');
        b[i][j] = '.';
      }
    }
  }
  for(auto x : b) cout << x << '\n';
}
void run(){
  int r, c; cin >> r >> c;
  vector<string> b(r);
  for(int i = 0; i < r; ++i) cin >> b[i];

  solve(b, r, c);
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}

// AC, implementation, dfs.
