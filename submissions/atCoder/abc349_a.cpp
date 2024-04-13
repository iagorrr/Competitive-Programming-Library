#include <bits/stdc++.h>
using namespace std;

auto run() {
	int n;
	cin >> n;
	int x = 0;
	for (int i = 0, y; i  < n-1;i ++) {
		cin >> y;
		x += y;
	}

	cout << -x << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	run();
}


// AC, games
