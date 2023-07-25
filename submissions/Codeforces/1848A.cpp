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

bool valid(int x, int y, int n, int m){
	return x >= 1 and y >= 1 and x <= n and y <= m;
}
void run() {
	ll n, m, k; cin >> n >> m >> k;
	ll x, y; cin >> x >> y;
	vector<pll> as(k);
	for(int i = 0; i < k; ++i) cin >> as[i].fst >> as[i].snd;

	int dx[4] = {1, -1, 0 ,0};
	int dy[4] = {0, 0, 1, -1};
	
	vector<char> impa(4);
	bool ans = false;
	for(int i = 0; i < 4; ++i) {
		if(!valid(x+dx[i], y+dy[i], n, m)) continue;
		ll x2 = x +dx[i];
		ll y2 = y + dy[i];
		for(int j = 0; j < k; j++) {
			ll dist = abs(x2-as[j].fst) + abs(y2-as[j].snd);
			if(dist&1) impa[i] = true;
		}
		ans |= (!impa[i]);
	}

	cout << (ans ?  "YES\n" : "NO\n"); 
}
int32_t main(void) {
  	fastio;
	int t;
	t = 1;
	cin >> t;
	while (t--)
		run();
}
