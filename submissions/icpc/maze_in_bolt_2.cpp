// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
#define INV(a)                                                                 \
  for (auto &x : a)                                                            \
  cin >> x
#define all(a) a.begin(), a.end()

void dbg_out() { cerr << endl; }
template <typename H, typename... T> void dbg_out(H h, T... t) {
  cerr << ' ' << h;
  dbg_out(t...);
}
#define dbg(...)                                                               \
  {                                                                            \
    cerr << #__VA_ARGS__ << ':';                                               \
    dbg_out(__VA_ARGS__);                                                      \
  }
bool pass(string &nut, vector<string> &s, int r, int c, int rc, int cc) {

  for(int i = 0; i < (int)nut.size(); ++i) {
    if(nut[i] == '1' and s[rc][(cc+i+c)%c] == '1') return false;
  }
  return true;
}
char solve(string &nut, vector<string> &s, int r, int c) {
  vector<vector<char>> check(r+1, vector<char>(c+1, 0));
  
  queue<pair<int, int>> q;

  for(int i = 0; i < c; ++i) {
    if(pass(nut, s, r, c, 0, i)){ 
      q.push({0, i});
    }
  }

  while(!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    if(x == r-1) return true;

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    for(int i = 0; i < 4; ++i){
      int x2 = x + dx[i]; 
      int y2 = y + dy[i];
      if(x2 >= 0 and x < r and !check[x2][(y2+c)%c] and pass(nut, s, r, c, x2, y2)) {
        check[x2][(y2+c)%c] = 1; 
        q.push({x2, (y2+c)%c});
      }
    }
  }
  
   return false;
}
void run() {
  int r, c;
  cin >> r >> c;
  string nut;
  cin >> nut;
  vector<string> screw(r);
  for (int i = 0; i < r; ++i) {
    string s;
    cin >> s;
    screw[i] = s;
  }

  if(solve(nut, screw, r, c)) {cout << "Y\n"; return;}
  reverse(all(nut));
  if(solve(nut, screw, r, c)) {cout << "Y\n"; return;}

  cout << "N\n";
}
int32_t main(void) {
  int t;
  t = 1;

  while (t--)
    run();
}

// AC, bfs
