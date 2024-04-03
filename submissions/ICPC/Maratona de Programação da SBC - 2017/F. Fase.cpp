#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> xs(n);

	for (auto &xi : xs) cin >> xi;
	
	sort(xs.rbegin(), xs.rend());

	int rep = 0, i = k;
	while (i < n and xs[k-1] == xs[i]) {
		i++;
		rep++;
	}

	cout << k + rep << '\n';
}

