#include <bits/stdc++.h>
using namespace std;

int T, D, M;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T >> D >> M;
	bool ans = false;

	vector<int> TS;
	TS.emplace_back(0);
	for (int i = 0, ti; i < M; i++) {
		cin >> ti;
		TS.emplace_back(ti);
	}
	TS.emplace_back(D);

	for (int i = 0; i + 1 < (int)TS.size(); i++) {
		//cerr << "TS[i]" << TS[i] << " TS[i+1]: " << TS[i+1] << '\n';
		ans |= TS[i+1] - TS[i] >= T;
	}

	cout << "NY"[ans] << "\n";

}

// AC, ad-hoc
