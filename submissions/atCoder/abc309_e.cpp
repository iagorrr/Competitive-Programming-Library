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
        ll n, m; cin >> n >> m;
        vector<vll> filhos(n+2);
        vll seguro(n+2, 0);
        for(int i = 2; i <= n; ++i) {
                ll p; cin >> p;
                filhos[p].pb(i);
        }
        for(int i = 0; i < m; ++i) {
                ll e, v; cin >> e >> v;
                seguro[e] = max(seguro[e], v+1);
        } 

        queue<ll> q;
        vector<char> processed(n+1);
        for(ll i = 1; i <= n; ++i) {
                if(processed[i]) continue;
                q.push(i);
                while(!q.empty()) {
                        auto pai = q.front(); q.pop();
                        processed[pai] = true;
                        for(auto filho : filhos[pai]) {
                                q.push(filho);
                                seguro[filho] = max(seguro[filho], seguro[pai]-1);
                        }
                }
        }
        ll ans = 0;
        for(int i = 1; i <= n; i++) {
                if(seguro[i]){
                        ans++;
                } 
        }
        cout << ans << '\n';
}
int32_t main(void) {
  	fastio;
	int t;
	t = 1;
	while (t--)
		run();
}

// AC, trees dfs
