#include <bits/stdc++.h>
using namespace std;

using ll = long long;
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
    if (p & 1) ans = prod(ans, b);
    p >>= 1;
    b = prod(b, b);
  }
  return ans;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	ll n, m, k;
	cin >> n >> m >> k;

	vector<vector<ll>> mat(m, vector<ll>(m, 1));
	
	map<char,int> id;
	for (int i = 0; i < k; i++) {
		string s;
		cin >> s;
		int x = id.count(s[0]) ? id[s[0]] : id.size();
		if (!id.count(s[0]))
			id[s[0]] = id.size();

		int y = id.count(s[1]) ? id[s[1]] : id.size();
		if (!id.count(s[1]))
			id[s[1]] = id.size();

		mat[x][y] = 0;
 	}


	auto ret = fpow<ll>(mat, n-1);
	ll s = 0 ;
	for (auto row : ret) {
		for (auto ij : row) {
			s = (ij + s) % MOD;
		}
	}
	cout << s << '\n';

}

// AC, matrices, dp
