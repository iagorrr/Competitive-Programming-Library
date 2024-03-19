#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int N;
vector<ll> XS[2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0, ti, di; i < N; i++) {
		cin >> ti >> di;
		XS[di].emplace_back(ti);
	}

	reverse(XS[0].begin(), XS[0].end());
	reverse(XS[1].begin(), XS[1].end());

	for (int i = 0; i < 2; i++) 
		if (XS[i].empty()) {
			cout << XS[!i][0] + 10 << '\n';
			return 0;
		}


	ll curt, curd;

	if (XS[0].back() < XS[1].back()) {
		curt = XS[0].back() + 10;
		curd = 0;
		XS[0].pop_back();
	}
	else {
		curt = XS[1].back() + 10;
		curd = 1;
		XS[1].pop_back();
	}

	while (!XS[0].empty() and !XS[1].empty()) {
		// the person just enter and go...
		if (XS[curd].back() <= curt) {
			curt = max(curt, XS[curd].back()+10);
			XS[curd].pop_back();
		}
		else { // need to decide which direction take
			if (XS[curd].back() <= XS[!curd].back()) {
				curt = XS[curd].back() + 10;
				XS[curd].pop_back();
			}
			else {
				if (XS[!curd].back() <= curt) {
					while (!XS[!curd].empty() and XS[!curd].back() <= curt) {
						XS[!curd].pop_back();
					}
					curt = curt + 10;
				}
				else {
					curt = XS[!curd].back() + 10;
					XS[!curd].pop_back();
				}

				curd = !curd;
			}
		}
	}

	for (int i = 0; i < 2; i++)
		if (!XS[i].empty()) {
			if (XS[i][0] >= curt) {
				curt = XS[i][0] + 10;
			}
			else curt = curt + 10;
		}


	cout << curt << '\n';

}

// AC, implementation
