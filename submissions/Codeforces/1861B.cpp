#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(__x) (int) __x.size()
using ll = long long;
using ld = long double;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using vi2d = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;
using vc = vector<char>;
#define all(a) a.begin(), a.end()
#define snd second
#define fst first
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)

const ll INF = 1e18;

bool run() {
	string s, t;
	cin >> s >> t;
	if(s == t) return true;	

	for (int i = len(s)-1; i >= 0; i--) {
		if(s[i] != t[i]) break;
		if(s[i] == '0' and t[i] == '0') return true;
	}

	for (int i = 0; i < len(s); i++) {
		if(s[i] != t[i]) break;
		if(s[i] == '1' and t[i] == '1') return true;

	}
	int n = len(s);
	for(int i = 0; i < n-1; i++) {
		if(s[i] == '0' and t[i] == '0' and s[i+1] == '1' and t[i+1] == '1') return true;
	}
	return false;
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  cin >> t;
  while (t--){
	 	if(run()) 
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}
}
// AC, strings, ad-hoc
