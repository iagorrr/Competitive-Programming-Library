// iagorrr ;)
#include <atomic>
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
#define ss second
#define ff first
#define mp make_pair

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

bool match(const vector<string> &a, const vector<string> &b){
  for(int i = 0; i < a.size(); ++i) {
    if(a[i] != b[i]) return false;
  }
  return true;
}
void run(){
 ll h, w; cin >> h >> w;
 vector<string> A(h); INV(A);
 vector<string> B(h); INV(B);
  
 bool breko = false;
  for(int s = 0; s < h; ++s) {
    for(int t = 0; t < w; ++t) {

      breko = false;
      for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
          if(A[(i+s)%h][(j+t) % w] != B[i][j]) {
            breko = true;
            break;
          }
        }
        if(breko) break;
      }

      if(not breko) {
        cout << "Yes\n";
        return;
      }
      
    }
  }
  
  cout << "No\n";
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}

// AC, implementation, matrix.
