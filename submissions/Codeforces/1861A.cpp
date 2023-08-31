#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(__x) (int)__x.size()
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

bool isprime(ll x) {
	if(x== 1) return false;
	if( x <= 3) return true;
	for(int i = 2; i < x; i++) {
		if(x%i == 0) return false;
	}
	return true;
}
void run() {
	string s;
	cin >> s;
	for(int i = 0; i < len(s); i++) {
		for(int j = i+1; j < len(s); j++) {
			ll cur = (s[i]-'0')*10 + s[j]-'0';
			if (isprime(cur)) {
				cout << cur << endl;
				return;
			}
		}
	}
	cout << -1 << endl;
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  cin >> t;
  while (t--) run();
}

// AC, math, brute forces
