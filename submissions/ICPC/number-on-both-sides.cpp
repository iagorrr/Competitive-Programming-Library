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
int n;
int k, l;
vll a(1e5+1);
vll b(1e5+1);
ll sumfront = 0, sumback = 0;	
multiset<ll> sfront, sback, candidate;
void add(const int p) {
	sumfront += a[p];
	sfront.insert(a[p]);
	if(len(sback) < l) {
		sumback += b[p];
		sback.insert(b[p]);
	}
	else {
		if(*sback.begin() < b[p]) {
			auto v = *sback.begin();
			sback.erase(sback.find(v));
			sumback -=  v;
			sumback += b[p];
			sback.insert(b[p]);
			candidate.insert(v);
		}
		else candidate.insert(b[p]);
	}
}

void remove(const int p) {
	sumfront -= a[p];
	sfront.erase(sfront.find(a[p]));
	if (sback.find(b[p]) != sback.end()) {
		sumback -= b[p];
		sback.erase(sback.find(b[p]));
		auto it = candidate.rbegin();
		sback.insert(*it);
		sumback += *it;
		candidate.erase(candidate.find(*it));
	}	
	else {
		candidate.erase(candidate.find(b[p]));
	}
}
void run() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> b[i];
	}
	cin >> k >> l;
	for(int i = 0; i < k; i++) {
		add(i);
	}
	int pl = k-1;
	int pr = n-1;
	ll ans = sumfront + sumback;
	while(pl >= 0) {
		remove(pl);		
		add(pr);
		ans = max(ans, sumfront+sumback);
		pl--, pr--;
	}
	ans = max(ans, sumfront+sumback);
	cout << ans << endl;
}
int32_t main(void) {
  // fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}


// AC, greedy, data structures
