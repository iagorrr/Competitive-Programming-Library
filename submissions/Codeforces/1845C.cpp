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

bool solve(const string &lower, 
		const string &upper, ll m, const vector<vll> &dpos, ll curi, ll prevpos){
	
	if(curi == m) return false;
	
	/*
	   the best digit to position i is the one that the first time it
	   appears after the prevpos is the greatest
	 */
	ll bestpos = -1;
	for(int i = lower[curi]; i <= upper[curi]; ++i) {
		ll digit = i-'0';
		// to use this digit it needs to appear after prevpos
		auto it = lower_bound(all(dpos[digit]), prevpos+1);
		if(it != dpos[digit].end()) 
			bestpos = max(bestpos, *it);
		/*
		   if this digit don't appears anymore i can take it
		   and whatever i take next will be valid.
		 */
		else
			return true;
	}
	return false or solve(lower, upper, m, dpos, curi+1, bestpos);
}
void run() {
	string s; cin >> s;
	ll m; cin >> m;
	string lower; cin >> lower;
	string upper; cin >> upper;

	// know each position of each digit
	vector<vll> pos(10);
	for(int i = 0; i < s.size(); ++i) {
		pos[s[i]-'0'].pb(i);
	}

	bool ans = solve(lower, upper, m, pos, 0, -1);
	cout << (ans ? "YES" : "NO") << '\n';
}
int32_t main(void) {
  	fastio;
	int t;
	t = 1;
	cin >> t;
	while (t--){
		run();
	}
}

