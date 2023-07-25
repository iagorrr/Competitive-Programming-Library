// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
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
	ll n, k; cin >> n >> k;
	vll bridge(n+1); 
	for(int i = 1; i <= n; ++i) cin >> bridge[i];

	vector<priority_queue<ll>> maxdist(k+1); // every distance for k
	vll previous(k+1);
	for(int i = 1; i <= n ; ++i) {
		ll cur = bridge[i];
		ll dist = i-previous[cur]-1;
		maxdist[cur].push(dist);
		previous[cur] = i;
	}

	ll ans = LLONG_MAX;
	for(int i = 1; i <= k; ++i){
		ll cur = i;
		ll distton = (n+1)-previous[cur]-1;
		maxdist[cur].push(distton);
	}

	for(int i = 1; i<= k; ++i) {
		if(maxdist[i].size()) {
			maxdist[i].push(maxdist[i].top()/2);

			maxdist[i].pop();
		}
	}

	for(int i = 1; i <= k; ++i) {

		if(maxdist[i].size()){
			ans= min(ans, maxdist[i].top());

		}
	}

	cout << ans << '\n';
}
int32_t main(void) {
  	fastio;
	int t;
	t = 1;
	cin >> t;
	while (t--)
		run();
}
