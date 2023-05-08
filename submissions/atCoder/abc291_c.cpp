// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;
using pll = pair<ll, ll>;
string solve(string s, int n) {
  set<pair<int,int>> u;
  u.insert({0, 0});
  int x = 0;
  int y = 0;
  unordered_map<char, int> dx; dx['R'] = 1;dx['L'] = -1;
  unordered_map<char, int> dy; dy['U'] = -1;dy['D'] = 1;
  for(auto &c : s) {
    x += dx[c]; 
    y += dy[c];
    if(u.count({x,y})) return "Yes";
    u.insert({x,y});
  }
  return "No";
}
int32_t main(void){ fastio;
  int n; cin >> n;
  string s; cin >> s;
  cout << solve(s, n) << '\n';
}

// AC, implementation, grid
