#include <bits/stdc++.h>
using namespace std;

using ll = long long;

using pll = pair<ll, ll>;

auto run() {
	int n;
	cin >> n;

	multiset<pll> st;
	for (int i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		st.emplace(b, a);

	}

	ll ans = 0;
	ll bcnt = 0;

	while (st.size() != 1) {
		auto [b0, a0] = *st.begin();
		auto [bn, an] = *st.rbegin();

			ll to_reach = b0 - bcnt;

			// pode comprar com custo 1 já
			if (to_reach <= 0) {
				st.erase(st.find({b0, a0}));
				ans += a0;
				bcnt += a0;
				continue;
			}

			// compra o que consiguir/precisar do que tá mais longe
			ll to_buy = min(to_reach, an);
			ans += (to_buy * 2ll);
			bcnt += to_buy;

			st.erase(st.find({bn,an}));
			if (to_buy < an) {
				st.emplace(bn, an-to_buy);
			}
	}

	if (st.size() == 1) {
		// quantos vou comprar com custo 2
		auto [b0, a0] = *st.begin();

		ll to_reach = max(0ll, b0 - bcnt);

		ll to_buy = min(to_reach, a0);

		ans += (2ll*to_buy);

		a0 -= to_buy;

		// resto com custo 1
		ans += a0;
	}

	cout << ans << '\n';
}


int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	run();
}

/*
   	AC, greddy, sortings

	tem cara de guloso isso aqui

	- compra todos que já estão com custo 1 e ainda falta comprar
	- pago 2 naquele que precisa de mais pra baratear

	- mantem num set ordenado pelos bi que da i tu remove so o suficiente pra baratear
	o uqe pre cisa de mnos


	? quando vale a pena comprar de um que já tenho o suficiente só pra baratear o de outo ?
		acho que quando tem um de custo 1, e falta trê spra algum que ainda
		n fechei ficar com custo 1 tbm
 */
