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
#define ss second
#define ff first
#define mp make_pair

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

void run(){
  int n; cin >> n;
  string s; cin >> s;

  int ans = -1;
  for(int i = 0; i < n; ++i) {
    if(s[i] == 'o'){

      bool fprev = false;
      if(i > 0 and s[i-1] == '-') fprev = true;


      int j = i;
      int cnt = 0;
      while(j<n and s[j] == 'o'){
        j++;
        cnt++;
      }

      if(fprev or (j<n and s[j] == '-')) ans = max(ans, cnt);
      i = j;
    }
  }

  if(ans == 0) ans = -1;
  cout << ans << '\n';
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}

// AC, implementation.
