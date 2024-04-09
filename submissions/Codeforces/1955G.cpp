#include <bits/stdc++.h>
using namespace std;

int n, m;
int grid[100][100];


int vis[100][100];

bool dfs(int k) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			vis[i][j] = 0;
		}
	}

	if (grid[0][0] % k) return false;

	vis[0][0] = 1;
	vector<pair<int,int>> st;
	st.emplace_back(0, 0);

	while (!st.empty()) {
		auto [x, y] = st.back();
		st.pop_back();

		if (x + 1 < n and !vis[x+1][y] and (!(grid[x+1][y] % k))) {
			vis[x+1][y] = 1;
			st.emplace_back(x+1, y);
		}

		if (y + 1 < m and !vis[x][y+1] and (!(grid[x][y+1] % k))) {
			vis[x][y+1] = 1;
			st.emplace_back(x, y+1);
		}
	}

	return	vis[n-1][m-1];
}

void solve() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	int ans = 1;
	int nm = grid[n-1][m-1];
	
	for (int i = 1; i * i <= nm; i++) {
		if (nm % i == 0) {
			if (dfs(i)) 
				ans = max(ans, i);

			if (nm / i != i) 
				if (dfs(nm/i)) 
					ans = max(ans, nm/i);
		}
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		solve();
	}
}

/*
   	AC, number theory, dfs

	> so tenta todos os divisores do [n-1][m-1], 
	pq vai vai ter que pegar o gcd com ele no final
	mesmo
 */
