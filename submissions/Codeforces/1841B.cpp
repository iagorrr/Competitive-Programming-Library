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
  ll n; cin >> n;
  ll x; 
  string ans = "1";
  bool corto = false;
  ll first = -1;

  cin >> x;
  first = x;
  n--;
  ll last = x;
  while(n--) {
    cin >> x;
    if(not corto){
      if(x >= last) {
        ans.push_back('1');
        last = x;
      }
      else {
        // posso cortar e colocar
        if(x < last and x <= first){
          corto = true;
          ans.push_back('1');
          last = x;
        }
        else {
          ans.push_back('0');
        }
      }
    }
    else {
      if(x >= last and x <= first) {
        ans.push_back('1');
        last = x;
      }
      else{
        ans.push_back('0');
      }
    }
  }

  cout << ans << '\n';
  return;
}
int32_t main(void){ fastio;
  int t; t = 1;
  cin >> t;  
  while(t--)
    run();
}

// AC, greedy
