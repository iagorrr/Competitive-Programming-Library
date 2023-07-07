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
	vector<string> m(3);
	for(int i = 0; i < 3; ++i) cin >> m[i];

	for(int i = 0; i < 3; ++i) {
		// vertical
		int v = 0;
		for(int j = 0; j < 3; ++j)
			if(m[j][i] == m[0][i]) v++;
		if(v == 3 and m[0][i] != '.') {
			cout << m[0][i] << '\n';
			return;
		}

		// horizontal
		int h = 0;
		for(int j = 0; j < 3; ++j)
			if(m[i][j] == m[i][0]) h++;

		if(h == 3 and m[i][0] != '.') {
			cout << m[i][0] << '\n';
			return;
		}

	}

	// d1
	int d1 = 0;
	for(int i = 0; i < 3; ++i)
		if(m[i][i] == m[0][0]) d1++;
	if(d1 == 3 and m[0][0] != '.') {
		cout << m[0][0] << '\n';
		return;
	}

	// d2
	int d2 = 0;
	if(m[0][2] == m[0][2]) d2++;
	if(m[1][1] == m[0][2]) d2++;
	if(m[2][0] == m[0][2]) d2++;
	if(d2 == 3 and m[0][2] != '.') {
		cout << m[0][2] << '\n';
		return;
	}

	cout << "DRAW\n";
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
