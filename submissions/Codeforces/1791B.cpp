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

void run(){
  int n; cin >> n;
  string s; cin >> s;
  
  int x = 0, y = 0;
  bool ans = false;
  for(auto c : s){
    switch (c) {
      case 'L':
        x--;
      break;
      case 'R':
        x++;
      break;
      case 'U':
        y++;
      break;
      case 'D':
        y--;
      break;
    }
    if(x== 1 and y == 1) ans = true;
  }

  cout << (ans ? "YES\n" : "NO\n");
}
int32_t main(void){ fastio;
  int t; t = 1;
  cin >> t;  
  while(t--)
    run();
}

// AC, implementation

