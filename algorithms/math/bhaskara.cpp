// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;
#define INV(xxxx) for(auto &xxx : xxxx) cin >> xxx;
#define all(a) a.begin(), a.end()
#define ss second
#define ff first
#define mp make_pair

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

const ld EPS = 1e-5;
void run(){
  ll a, b, c; cin >> a >> b >> c;

  ld delta = (ld) b * b - 4.0*a*c;

  // infinite root count.
  if(a == 0 and b == 0 and c == 0) { // infinite root.
    cout << -1 << '\n';
  }
  else if (a == 0 and b == 0) {// no root.
    cout << 0 << '\n';
  }
  else if (a == 0) {
    cout << 1 << '\n';
    cout << ((ld) -c) / (b) << '\n';
  }
  else if (abs(delta) <= EPS) { // one root.
    cout << 1 << '\n';
    cout << ((ld)-b) / (2*a) << '\n';
  }
  else if (delta < 0) { // no root.
    cout << 0 << '\n';
  }
  else { // two distinct roots
    cout << 2 << '\n';
    ld x1 = ((ld) -b + (ld) sqrt(delta)) / (2.0*(ld)a);
    ld x2 = ((ld) -b - (ld) sqrt(delta)) / (2.0*(ld)a);
    if(x1 > x2) swap(x1, x2);
    cout << x1 << '\n' << x2 << '\n';
    
  }

}
int32_t main(void){ fastio;

  cout.precision(12);
  int t; t = 1;
  
  while(t--)
    run();
}

