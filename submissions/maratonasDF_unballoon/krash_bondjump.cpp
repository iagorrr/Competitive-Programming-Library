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
	vll xs(n);
	for(int i = 0; i < n; ++i) {
		cin >> xs[i];
	}


	// solucao nada otimizada
	vector<char> canreach(n);
	canreach[0] = true;
	for(int i = 0; i < n; ++i) {
		if(!canreach[i]) continue;
		ll k = xs[i];
		do {
			canreach[min(i+k, n-1)] = true;
		} while(k--);
	}

	string ans = canreach[n-1] ? "Possivel" : "Impossivel";
	cout << ans << " passar\n";
}
int32_t main(void) {
  	fastio;
	int t;
	t = 1;
	cin >> t;
	while (t--)
		run();
}
	
// AC, implementation
