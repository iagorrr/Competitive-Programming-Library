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

int fastlog2(ll x){
  ll i = x;
  return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}
template<typename T>
class SparseTable {
  public:
    int N;
    int K;
    vector<vector<T>> st;
    SparseTable(vector<T> vs) : N((int)vs.size()), K(fastlog2(N) + 1), st(K+1, vector<T>(N+1)) {
      copy(vs.begin(), vs.end(), st[0].begin());

      for(int i = 1; i <= K; ++i)
        for(int j = 0; j + (1<<i) <= N; ++j)
          st[i][j] = min(st[i-1][j], st[i-1][j+(1 << (i-1))]);
    }
    T RMQ(int l, int r) {
      int i = fastlog2(r-l+1);
      return min(st[i][l], st[i][r-(1<<i)+1]);
    }
};

void run(){
  ll n, q; cin >> n >> q;
  vll xs(n); INV(xs);
  SparseTable <ll> st(xs);
  for(int i = 0; i < q; ++i) {
    ll a, b; cin >> a >> b;
    cout << st.RMQ(a-1,b-1) << '\n';
  }
}
int32_t main(void){ fastio;
  int t; t = 1;
  
  while(t--)
    run();
}
