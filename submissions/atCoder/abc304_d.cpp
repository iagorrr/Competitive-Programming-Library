// iagorrr ;)
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define INV(xxxx) for(auto &xxx : xxxx) cin >> xxx;
#define all(a) a.begin(), a.end()
#define snd second
#define fst first

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

vector<pll> pedacos(2*1e5+1);
ll A, B, W, H, N;
vll cortea(2*1e5+1);
vll corteb(2*1e5+1);
map<pair<ll,ll>, ll> ans;
pair<ll,ll> findpos(pll p) {
  pll pos;
  pos.first = pos.second = 0;

  int l = 0, r = A-1;
  while(l <= r) {
    int mid = (r-l)/2 + l;
    if(cortea[mid] <= p.first) {
      pos.first = mid+1;
      l = mid+1;
    }
    else r = mid -1;
  }

  l = 0, r = B-1;
  while(l <= r) {
    int mid = (r-l)/2 + l;
    if(corteb[mid] <= p.second) {
      pos.second = mid+1;
      l = mid+1;
    }
    else r = mid -1;
  }

  return pos;
}

void run(){
  cin >> W >> H;
  cin >> N;

  for(int i = 0; i < N; ++i) {
    cin >> pedacos[i].first >> pedacos[i].second;
  }

  cin >> A;
  for(int i = 0; i < A; ++i) 
    cin >> cortea[i];

  cin >> B;
  for(int i = 0; i < B; ++i) 
    cin >> corteb[i];

  for(int i = 0; i < N; ++i) {
    // auto pos = findpos(pedacos[i]);
    ans[findpos(pedacos[i])]++;
    // dbg(pedacos[i].first, pedacos[i].second, pos.first, pos.second);
  }

  ll m = LLONG_MAX, M=-1;
  for(auto [p, q] : ans) {
    M = max(M, q);
    m = min(m, q);
  }
  if((ll)ans.size() < (A+1)*(B+1)) m = 0;
  cout << m << ' ' << M << '\n';
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}
// AC, Binary search
