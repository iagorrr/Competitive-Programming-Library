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
  vll a(n); INV(a);

  a[0]--;
  int bob=1;
  for(int i = 1; i < n; ++i) {
    if(a[i] < a[bob]) bob = i;
  }

  int alice = 0;
  for(int i = 0; i < n; ++i){
    if(i != bob and (a[i] < a[alice])) alice = i;
  }
  
  ll va = a[alice];
  ll vb = a[bob]-1;
  
  // cout << alice << ' ' << va << ' ' << bob << ' ' << vb << '\n';
  cout << (va <= vb ? "Bob" : "Alice") << '\n';
}
int32_t main(void){ fastio;
  int t; t = 1;
  cin >> t;  
  while(t--)
    run();
}

// AC, implementation, games.
