#include <bits/stdc++.h>
using namespace std;

auto run() {
	int q;
	cin >> q;

	map<int, char> side;
	map<int, int> ql, qr;

	int qtdl, qtdr;
	qtdl = qtdr = 0;

	while (q--) {
		char o;
		cin >> o;

		int id;
		cin >> id;

		if (o == '?') {
			int qid = ql[id] + qr[id];
			if (qid == 1) {
				int a = qtdl;
				int b = qtdr;
				if (side[id] == 'L') a--;
				else b--;
				cout << min(a,b) << '\n';
			}
			else {
				// tirar pelo mesmo lado que entrou
				int a;
				if (side[id] == 'L') {
					a = qtdl - ql[id];
				}
				else {
					a = qtdr - qr[id];
				}

				// tirar pelo lado oposto
				int b;
				if (side[id] == 'L') {
					b = ql[id]+qtdr - 1;
				}
				else {
					b = qr[id] + qtdl - 1;
				}
				cout << min(a, b) << '\n';
			}

		}
		else {

			if (o == 'L') qtdl++;
			else qtdr++;

			side[id] = o;
			ql[id] = qtdl;
			qr[id] = qtdr;
		}
	}	
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt = 1;
	// cin >> tt;

	while (tt--) {
		run();
	}
}

// AC, ad-hoc
