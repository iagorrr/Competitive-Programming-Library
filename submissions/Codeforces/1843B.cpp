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

void run(){
  ll n; 
  cin >> n;
  vll a(n); INV(a);

  ll sum = 0;
  ll op = 0;
  bool open = false;;
  for(int i = 0; i < n; ++i) {
    sum += abs(a[i]);
    if(open){
      if(a[i] <= 0) {
        continue;
      } 
      else {
        open = false;
      }
    }
    else {
      if(a[i] < 0 ){
        op++;
        open = true;
      } 
    }
  }
  cout << sum << ' ' << op << '\n';
}
int32_t main(void){ fastio;
  int t; t = 1;
  cin >> t; 
  while(t--)
    run();
}

// AC, greedy.
