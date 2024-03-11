#include <bits/stdc++.h>
using namespace std;

int sum(int a, int d, int n) {
	return (a + d) % n;
}

int sub(int a, int d, int n) {
	return (a - d + n) % n;
}

void solve() {
	int n, m,  x;
	cin >> n >> m >> x;
	x--;

	vector<pair<int, char>> plays(m);
	for (auto &[a, c] : plays) cin >> a >> c;
	

	set<int> cur;
	cur.emplace(x);
	for (auto [dx, dir] : plays) {
		set<int> next;

		if (dir == '0' or dir == '?') {
			for (auto i : cur)
				next.emplace(sum(i, dx, n));

		}

		if (dir == '1' or dir == '?') {
			for (auto i : cur)
				next.emplace(sub(i, dx, n));
		}
		cur.swap(next);
	}

	cout << cur.size() << '\n';
	for (auto i : cur) {
		cout << i+1 << ' ';
	}
	cout << '\n';


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


// AC, brute force
