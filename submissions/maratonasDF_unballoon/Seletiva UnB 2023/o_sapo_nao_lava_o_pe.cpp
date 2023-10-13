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

string transform(string s, char c) {
	string v {"aeiouAEIOU"};
	for(auto &ci : s) {
		if(find(all(v), ci) != v.end()){
			if(islower(ci)) ci = tolower(c);
			else ci = toupper(c);
		}
	}
	return s;
}
void run() {
	string s; getline(cin, s);	
	char c;
	while(cin >> c) {
		auto  ans = transform(s, c);
		cout << ans << '\n';
	}
}
int32_t main(void) {
  	fastio;
	int t;
	t = 1;
	while (t--)
		run();
}

// AC, strings, implementation
