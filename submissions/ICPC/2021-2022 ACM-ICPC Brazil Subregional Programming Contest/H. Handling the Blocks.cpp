#include <bits/stdc++.h>
using namespace std;

const int MAXK(1'00'000);
int N, K;

multiset<int> percolor[MAXK];
int colors[MAXK];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	
	for (int i = 0, ni, ci; i < N; i++) {
		cin >> ni >> ci;
		ci--;
		percolor[ci].emplace(ni);
		colors[i] = ci;
	}

	vector<int> xs;
	for (int i = 0; i < N; i++) {
		auto ci = colors[i];
		xs.emplace_back(*percolor[ci].begin());
		percolor[ci].erase(percolor[ci].begin());
	}

	for (int i = 1; i < N; i++) {
		if (xs[i] < xs[i-1]) {
			cout << "N\n";
			return 0;
		}
	}

	cout << "Y\n";
}

// AC, ad-hoc
