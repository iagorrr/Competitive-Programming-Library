// iagorrr ;)
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
	vll xs(n); INV(xs);
	ll andall = xs[0];

	for(auto xi : xs) andall &= xi;
	if(andall) {
		// whatever partition i make this i will appear more than once
		cout << 1 << '\n';
		return;
	}

	ll curand = xs[0];
	ll cuts = 0;
	for(int i = 0; i < n; ++i) {
		curand &= xs[i];
		if(i == n-1){
			if(curand != 0) {
				// so i shouldn't make the previous cut
				cuts--;
			}
		}
		else {
			if(curand == 0){
				// than i cut and start a new segment at xs[i+1]
				cuts++;
				curand = xs[i+1];
			}
		}
	}

	cout << cuts+1 << '\n';
}
int32_t main(void) {
  	fastio;
	int t;
	t = 1;
	cin >> t;
	while (t--)
		run();
}

// AC, greedy, bitmask
