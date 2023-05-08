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

bool passall(string &nut, vector<string> &s, int r, int c, int rc, int cc, vector<vector<char>> &check) {
  if(rc == r-1){
    return true;
  } 

  check[rc][(cc+c)%c] = 1; 
  if(rc > 0  and !check[rc-1][cc] and pass(nut, s, r, c, rc-1, cc) and passall(nut, s, r, c, rc-1, cc, check)) {
    return true;
  } 
  if(rc+1 < r and !check[rc+1][cc] and pass(nut, s, r, c, rc+1, cc) and passall(nut, s, r, c, rc+1, cc, check)) {
    return true;
  } 
  if(!check[rc][(cc+c-1)%c] and pass(nut, s, r, c, rc, (cc+c-1)%c) and passall(nut, s, r, c, rc, (cc+c-1)%c, check)) {
    return true;
  }
  if(cc+1 <= c and !check[rc][(cc+c+1)%c] and pass(nut, s, r, c, rc, (cc+c+1)%c) and passall(nut, s, r, c, rc, (cc+c+1)%c, check)) {
    return true;
  }

  return false;
}
char solve(string &nut, vector<string> &s, int r, int c) {
  vector<vector<char>> dp(r, vector<char>(c+1, 0));
  
  for(int i = 0; i < c; ++i) {
    if(pass(nut, s, r, c, 0, i)){ 
      if( passall(nut, s, r, c, 0, i, dp) ) return true;
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

// AC, dfs.
