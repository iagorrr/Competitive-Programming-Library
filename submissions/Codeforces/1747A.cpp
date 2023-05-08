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

  ll s1 = 0, s2 = 0;
  sort(all(a));
  for(auto x : a) {
    if(x<= 0) s1+=x;
    else s2 += x;
  }
  // cout << s1 << ' ' << s2 << '\n';
  cout << abs(abs(s1)-abs(s2)) << '\n';
}
int32_t main(void){ fastio;
  int t; t = 1;
  cin >> t;  
  while(t--)
    run();
}

// AC, implementation.
