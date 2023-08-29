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

ld nfirst(ld n) {
	return (ld)(n * (n+1)) / (ld)2;
}
void run() {
	int n, a, b;
	cin >> n >> a >> b;
	vector<ld> ev(n+1, 0);	
	vector<ld> psum(n+1, 0);
	ld range = b-a+1;
	for (int i = 1; i <= n; i++) {
		int l = max(0, i - b);
		int r = max(0, i - a);
		if(a == 0) r = max(0, r-1);
		ev[i] = 0;

		// optimize with psum later.
		ev[i] = (psum[r]-psum[max(l-1, 0)]) * (1/(range-(a==0)));
		/*
		for(int j = l; j <= r; j++) {
			if(a == 0)
				ev[i] += (ev[j] * ((ld)1/(range-1)));
			else
				ev[i] += (ev[j] * ((ld)1/range));
		}
		*/
		if(a == 0) {
			ev[i] += (range/(range-1));
		}
		else {
			ev[i] += 1;
		}

		psum[i] = psum[i-1]+ev[i];
	}
	cout << fixed << setprecision(9) << ev[n] << endl;
}
int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}


// AC, Expected value, prefix sum
