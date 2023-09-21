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

void run() {
	int n;
	cin >> n;
	int john = 0;
	multiset<int> cartas;
	for (int i = 0; i < 4; i++) {
		for(int j = 1; j <= 13; j++) {
			cartas.insert(min(j, 10));
		}
	}
	for(int i = 0; i < 2; i++){
		int c;
		cin >> c;
		c = min(c, 10);
		john += min(c, 10);
		cartas.erase(cartas.find(c));
	}

	int mary = 0;
	for(int i = 0; i < 2; i++){
		int c;
		cin >> c;
		c = min(c, 10);
		mary += min(c, 10);
		if(cartas.find(c) != cartas.end())
			cartas.erase(cartas.find(c));
	}
	
	int common = 0;
	for(int i = 0; i < n; i++) {
		int c;
		cin >> c;
		c = min(c, 10);
		common += c;
		if(cartas.find(c) != cartas.end())
			cartas.erase(cartas.find(c));
	}
	
	for(int i = 1; i <= 10; i++) {
		if(john+common+i > 23 and mary + common + i <= 23 and cartas.find(i) != cartas.end()){
			cout << i << endl;
			return;
		}
		if(mary + common + i == 23 and cartas.find(i) != cartas.end()) {
			cout << i << endl;
			return;
		}
	}
	cout << -1 << endl;
}

int32_t main(void) {
  fastio;
  int t;
  t = 1;
  // cin >> t;
  while (t--) run();
}


// AC, implementation
