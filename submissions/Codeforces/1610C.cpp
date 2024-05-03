#include <bits/stdc++.h>
using namespace std;

/*
	two pointers secao ?
	se to com u certo l e o r atual não deixa ser pego
	pq o l tá mt longe eu paro

	n da né as vezes vale a pena pular alguem que é 'chato' pra pegar
	alguém que permite maiso

	mas com um l e r fixo da pra saber quntos consigo pegar em tempo bom ?
	linear serve tbm

	se ja sei que nesse l r todo mundo pode pegar todo mundo
	
 */
auto run() {
	int n;
	cin >> n;

	vector<int> as(n), bs(n);
	for (int i = 0; i < n; i++) {
		cin >> as[i] >> bs[i];
	}

	auto check = [&](int m) -> bool {
		int cnt = 0; 
		for (int i = 0; i < n; i++) {
			if (bs[i] >= cnt and m-1-cnt <= as[i]) cnt++;

		}
		return cnt >= m;
	};

	int ans = 0;
	for (int l = 0, r = n; l <= r; ) {
		int m = midpoint(l, r);
		
		if (check(m)) {
			l  = m + 1;
			ans = max(ans, m);
		}
		else r = m - 1;
	}

	cout << ans << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		run();
}

// AC, greddy, binary search
