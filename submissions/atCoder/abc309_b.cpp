// iagorrr ;)
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define rep(i, l, r) for (int i = (l); i < (r); i++)
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using pii = pair<int, int>;
#define INV(xxxx)                                                              \
  for (auto &xxx : xxxx)                                                       \
    cin >> xxx;
#define all(a) a.begin(), a.end()
#define snd second
#define fst first
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)


void dbg_out() { cerr << endl; }
template <typename H, typename... T> void dbg_out(H h, T... t) {
  cerr << ' ' << h;
  dbg_out(t...);
}
#define dbg(...)                                                               \
  {                                                                            \
    cerr << #__VA_ARGS__ << ':';                                               \
    dbg_out(__VA_ARGS__);                                                      \
  }

void run() {
        ll n; cin >> n;

        vector<string> m(n);
        for(auto &mi : m) cin >> mi;

        vector<string> m2;
        m2 = m;
        
        // first column
        for(int i  = 0; i < n-1; ++i) {
                m2[i][0] = m[(i+1)][0];
        }

        // first line
        for(int i  = n-1; i >= 1; --i) 
                m2[0][i] = m[0][i-1];



        // last column
        for(int i  = n-1; i >= 1; --i) 
                m2[i][n-1] = m[(i-1)%n][n-1];

        // last line
        for(int i  = 0; i < n-1; ++i) 
                m2[n-1][i] = m[n-1][(i+1)%n];

        for(auto mi2 : m2) 
                cout << mi2 << '\n';

}
int32_t main(void) {
  	fastio;
	int t;
	t = 1;
	while (t--)
		run();
}

// AC, implementation, grid
