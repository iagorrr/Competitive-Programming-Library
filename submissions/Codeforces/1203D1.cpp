#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	string t;
	cin >> s >> t;

	map<char, vector<int>> pos_char;
	for (int i = 0; i < (int)s.size(); i++) {
		pos_char[s[i]].push_back(i);
	}


	auto check2 = [&](int l, int r) -> bool {
		int p = -1;
		for (auto c : t) {
			bool found = false;
			for (auto pc : pos_char[c]) {
				if (pc > p and (pc < l or pc > r)) {
					p = pc;
					found = true;
					break;
				}
			}
			if (!found) return false;
		}
		return true;
	};

	auto check = [&](int m) -> bool {
		for (int l = 0, r = m -1; r < (int)s.size(); l++, r++) {
			if (check2(l, r)) return true;
		}
		return false;
	};

	int ans = 0;
	for (int l = 1, r = (int)s.size(); l <= r; ) {
		int m = (l+r)/2;
		if (check(m)) {
			ans = max(ans, m);
			l = m + 1;
		}
		else r = m - 1;
	}

	cout << ans << '\n';
}

/*
	bb no tamanho

	check:
		testa todos as substring de tamanho MID : N
			checa se removendo aquela sub da
			pra tirar a subseq: N
	logN * N*N
 */
