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
#define eb emplace_back
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

auto run() 
{
	int n;
	cin >> n;

	vll xs(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> xs[i];
	}

	set<ll> st;

	vector<pii> ans;
	int l = 1;
	for (int i = 1; i <= n; i++) {
		auto xi = xs[i];
		if (st.count(xi)) {
			ans.eb(l, i);
			st.clear();
			l = i+1;
		}
		else {
			st.emplace(xi);
		}
	}

	if (len(ans) == 0) {
		cout << -1 << '\n';
	}
	else {
		if (len(st)){
			ans.back().second = n;
		}
		cout << len(ans) << '\n';
		for (auto [a, b] : ans) {
			cout << a << ' ' << b << '\n';
		}
	}

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
