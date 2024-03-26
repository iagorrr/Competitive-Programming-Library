#include <bits/stdc++.h>
using namespace std;

int grid[100][100];

void add(int d, int l, int r, int c) {
	int dx = 0, dy = 1;
	if (d) swap(dx, dy);
	for (int i = 0; i < l; i++) 
		grid[r+dx*i][c+dy*i]++;
}

bool check() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (grid[i][j] > 1)
				return false;
			if ((i < 1 or j < 0 or i > 10 or j > 10) and grid[i][j])
				return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;

	for (int i = 0, d, l, r, c; i < n; i++) {
		cin >> d >> l >> r >> c;
		add(d, l, r, c);
	}

	cout << (check() ? "Y" : "N") << '\n';
}
