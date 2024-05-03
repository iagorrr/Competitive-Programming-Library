#include <bits/stdc++.h>
using namespace std;

/*
	to feito se tiver o de menor L e o de maior R
	fode se:
		o com maior for o mesmo do com menor
			na vdd n né pq todo o resto vai estar no mesmo lugar 
			
	comprar u msó que tem os dois, maior e menor

	ou comprar 2, dai pega os com mnofjsoadjfosadjfoasjfoais
 */

auto run() {
	int n;
	cin >> n;

	using t3 = tuple<int,int,int>;

	auto f1 =  [&](const t3 &x, const t3 &y) ->bool {
			auto [a1, _, c1] = x;
			auto [a2, __, c2] = y;
			return !(a1 == a2 ? c1 <= c2 : a1 <= a2);
	};

	 auto f2 = [](const t3 &x, const t3 &y) -> bool {
			auto [_, b1, c1] = x;
			auto [__, b2, c2] = y;

			return !(b1 == b2 ? c1 <= c2 : b1 >= b2);
	};



	auto f3 = [](const t3 &x, const t3 &y) -> bool {
			auto [a1, b1, c1] = x;
			auto [a2, b2, c2] = y;
			if (a1 == a2) {
				if (b1 == b2) {
					return !(c1 <= c2);
				}
				else {
					return !(b1 >= b2);
				}
			}
			else return !(a1 <= a2);

	};

	priority_queue<t3, vector<t3>, decltype(f1)> c1(f1);
	priority_queue<t3, vector<t3>, decltype(f2)> c2(f2);
	priority_queue<t3, vector<t3>, decltype(f3)> c3(f3);

	for (int i = 0; i < n; i++) {
		int a, b,c;
		cin >> a >> b >> c;

		c1.push({a,b,c});
		c2.push({a,b,c});
		c3.push({a,b,c});

	

		auto [l, _, cl] = c1.top();
		auto [__, r, cr] = c2.top();
		auto [l2, r2, crl] = c3.top();

		int cur = cl + cr;
		if (l2 == l and r2 == r) cur = min(cur, crl);
		cout << cur << '\n';
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt;
	cin >> tt;

	while(tt--)
		run();
}

// AC, sortings, greddy, data structures
