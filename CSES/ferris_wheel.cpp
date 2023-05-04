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
  ll n, x; cin >> n >> x;
  vll xs(n);
  for(int i = 0; i < n; ++i) cin >> xs[i];

  ll ans = 0;
  multiset<ll> st;

  for(auto xi : xs) st.insert(xi);


  while(st.size()){
    if(st.size() > 1 and (*std::prev(st.end()) + *st.begin() <= x)) {
      // cout << *st.begin() << ' ' << *prev(st.end()) << '\n';
      st.erase(st.begin());
      st.erase(prev(st.end()));
    }
    else {
      // cout << *prev(st.end()) << '\n';
      st.erase(prev(st.end())); 
    }
    ans++;
  } 
  cout << ans << '\n';
}
int32_t main(void){ //fastio;

  int t; t = 1;
  
  while(t--)
    run();
}

// AC, sorting and searching.
