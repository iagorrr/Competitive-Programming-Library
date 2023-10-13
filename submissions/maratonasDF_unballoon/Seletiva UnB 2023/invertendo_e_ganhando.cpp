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

string solve(string s, ll i, ll k, ll n) {
	if(i == k) return s;

	string ans = s;
	string so = s;
	vector<pll> totry;

	// da pra melhorar isso aq
	ll pos = -1;
	for(int a = 0; a < n; ++a){
		bool found = false;
		for(int b = a+1; b < n; ++b){
			if(s[b] > s[a]) {
				found = true;
				pos = a;
				break;
			}
		}
		if(found) break;
	}

	if(pos == -1){
	       	return s;
	}

	auto maxdigit = s[pos];
	for(int a = pos+1; a < n; ++a) maxdigit = max(maxdigit, s[a]);
	for(int a = pos+1; a < n; ++a) {
		if (s[a] == maxdigit){
			totry.pb(mp(pos, a));
		}
	}

	for(auto [a, b] : totry){
			swap(so[a], so[b]);
			ans = max(ans, solve(so, i+1, k, n));
			swap(so[a], so[b]);
	}

	return ans;
}
void run() {
	ll n, k; cin >> n >> k;
	string s; cin >> s;
	cout << solve(s, 0, k, n) << '\n';
}
int32_t main(void) {
  	fastio;
	int t;
	t = 1;
	while (t--)
		run();
}

// AC, bruteforce, backtracking
