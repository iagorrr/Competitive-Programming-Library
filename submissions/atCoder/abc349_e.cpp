#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll grid[3][3];
ll game[3][3];


bool check() {
	ll a, b;
	a = b = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			a += (game[i][j] == 1) * grid[i][j];
			b += (game[i][j] == 2) * grid[i][j];
		}
	}
	
	return a > b;
}

bool check2(int p) {

	for (int i = 0; i < 3; i++) {
		bool row = true;
		bool col = true;
		bool d1 = true;
		bool d2 = true;
		for (int j = 0; j < 3; j++) {
			row &= (game[i][j] == p);
			col &= (game[j][i] == p);
			d1 &= (game[j][j] == p);
			d2 &= (game[2-j][j] == p);
		}
		if (row ||  col || d1 || d2) return true;
	}


	return false;
}


bool solve(int m) {
	if (m == 9) {
		return !check();
	}

	int p = (m&1) + 1;

	bool ans = false;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)  {
			if (game[i][j] != -1) continue;
			game[i][j] = p;

			if (check2(p)) ans |= true;
			else ans |= (!solve(m+1));

			game[i][j] = -1;

		}

	}

	return ans;
}

auto run() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			game[i][j] = -1;
			cin >> grid[i][j];
		}
	}

	cout << (solve(0) ? "Takahashi" : "Aoki" ) << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie();

	run();
}
/*
	AC, games, brute force
 */



