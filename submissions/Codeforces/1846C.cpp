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
	ll n,  m, h;
	cin >> n >> m >> h;
	vector<vll> t(n, vll(m));
	for(int i = 0 ; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >> t[i][j];
		}
	}

	// -points, penality, id
	vector<array<ll, 3>> r(n);
	for(int i = 0; i < n; ++i) {
		sort(all(t[i]));
		ll ti = 0;
		ll penali = 0;
		ll pointsi = 0;
		for(int j = 0; j < m; ++j) {
			if(ti + t[i][j] > h) break;

			pointsi++;
			ti += t[i][j];
			penali += ti;
		}

		r[i] = {-pointsi, penali, i};
	}

	sort(all(r));
	ll ans = -1;
	for(int i = 0; i < n; ++i){
		if(r[i][2] == 0){
			ans = i;
			break;
		}
	}
	cout << ans+1 << '\n'; }
int32_t main(void) {
  	fastio;
	int t;
	t = 1;
	cin >> t;
	while (t--)
		run();
}

// AC, implementation
