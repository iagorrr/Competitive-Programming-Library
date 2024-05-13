/*
	é um de ordem M,
	arrasta o blocao pra trás até M  - 1 vezes
	F(M) = 2
	F(i), i < M = 1
 */
#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long;
#define len(x) (int)x.size()

ll MOD = 1'000'000'007;

template <typename T>
vector<vector<T>> prod(vector<vector<T>> &a,
                       vector<vector<T>> &b) {
  int n = len(a);
  vector<vector<T>> c(n, vector<T>(n));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        c[i][j] =
          (c[i][j] + ((a[i][k] * b[k][j]) % MOD)) % MOD;
      }
    }
  }

  return c;
}

template <typename T>
vector<vector<T>> fpow(vector<vector<T>> &xs, ll p) {
  vector<vector<T>> ans(len(xs), vector<T>(len(xs)));
  for (int i = 0; i < len(xs); i++) ans[i][i] = 1;

  auto b = xs;
  while (p) {
    if (p & 1ll) ans = prod(ans, b);
    p >>= 1ll;
    b = prod(b, b);
  }
  return ans;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll n, m;
	cin >> n >> m;
	if (m > n) {
		cout << 1 << '\n';
		return 0;
	}
	if (m == n) {
		cout << 2 << '\n';
		return 0;
	}
	if (m + 1 == n) {
		cout << 3 << '\n';
		return 0;
	}
	vector<vector<ll>> tl(m, vector<ll>(m));
	tl[0][0] = 1;
	tl[0][m-1] = 1;
	for (int i = 1, j = 0; i < m; i++, j++) tl[i][j] = 1;

	auto tl2 = fpow<ll>(tl, n-m);

	/*
	for (auto i : tl2) {
		for (auto j : i)
			cerr << j << ' ';
		cerr << '\n';
	}
	*/

	ll ans = 0;
	for (auto  i : tl2) {
		for (auto j : i) {
			ans = (ans + j) % MOD;
		}
		ans = (ans + *i.begin()) % MOD;
		break;
	}
	cout << ans << '\n';

}


// AC, matrices
