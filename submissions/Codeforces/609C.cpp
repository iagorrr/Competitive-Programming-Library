#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...) 42
#endif
#define endl '\n'
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define len(__x) (int)__x.size()
using ll = long long;
using ull = unsigned long long;
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
#define pb(___x) push_back(___x)
#define mp(___a, ___b) make_pair(___a, ___b)
#define eb(___x) emplace_back(___x)
int lg2(ll x) {
  return __builtin_clzll(1) - __builtin_clzll(x);
}

// vector<string> dir({"LU", "U", "RU", "R", "RD", "D",
// "LD", "L"}); int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}; int
// dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<string> dir({"U", "R", "D", "L"});
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

const ll oo = 1e18;
int T(1);
const int MAXN(1'000'000);


ll N;
auto run() {
	cin >> N;

	vll xs(N);
	ll totsum = 0;
	for (auto &xi : xs){
		cin >> xi;
		totsum += xi;
	}

	if ( N == 1) {
		cout << 0 << '\n';
		return;
	}

	ll avg = totsum / N;
	ll rest = (totsum % N)  != 0;

	sort(all(xs));

	ll increase, decrease;
	increase = decrease = 0;
//	cout << avg << ' ' << rest << '\n';
	for (auto xi : xs) {
		if (rest) {
			ll d1 = abs(xi-avg);
			ll d2 = abs(xi-(avg+rest));

			if (d1 < d2) {
				increase += d1;
			}
			else {
				decrease += d2;
			}

		}
		else {
			ll d1 = abs(xi-avg);
			if (xi < avg) increase += d1;
			else decrease += d1;
		}

	}

//	cout << decrease << ' ' << increase << '\n';
	cout << max(increase, decrease) << '\n';

}

int32_t main(void) {
#ifndef LOCAL
  fastio;
#endif

  // cin >> T;

  for (int i = 1; i <= T; i++) {
    run();
  }
}

