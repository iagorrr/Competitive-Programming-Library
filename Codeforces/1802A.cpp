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
  vi a(n); INV(a);

  sort(all(a), greater<int>());
  set<int> st(all(a));
  int cnt = 0;
  for(auto x : a){
    cnt += (x>0 ? 1 : -1);
    cout <<  cnt << " ";
  }
  cout << '\n';


  int l = 0;
  int p = 0;
  for(auto x : a) {
    p += x>0;
    l += x<0;
  }

  while(l--) {
    cout << "1 0 ";
    p--;
  }

  for(int i = 1; i <= p; ++i) cout << i << " ";
  cout << '\n';
}
int32_t main(void){ fastio;
  int t; t = 1;
  cin >> t; 
  while(t--)
    run();
}
