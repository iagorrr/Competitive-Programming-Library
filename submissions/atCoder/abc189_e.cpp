#include <bits/stdc++.h>
using namespace std;


using ll = long long;
auto run() {
	int N;
	cin >> N;
	vector<pair<ll,ll>> XS(N);
	for (auto &[a, b]: XS) {
		cin >> a >> b;
	}

	int M;
	cin >> M;
	vector<pair<ll,ll>> MS(M);
	for (auto &[a, b]: MS) {
		cin >> a;
		if (a > 2) cin >> b;
	}

	int Q;
	cin >> Q;
	vector<tuple<ll,ll,int>> QS(Q);
	for (int i = 0; i < Q; i++) {
		auto &[a, b, c] = QS[i];
		cin >> a >> b;
		b--;
		c = i;
	}

	sort(QS.begin(), QS.end());

	bool swp = false;
	ll sign_x, sign_y;
	sign_x = sign_y = 1;
	ll ofs_x, ofs_y;
	ofs_x = ofs_y = 0;


	// operations first
	// swap later

	auto apply = [&](int i) -> void {
		auto [a, b] = MS[i];
		if (a == 1) {
			swp = !swp;
			swap(ofs_y, ofs_x);
			swap(sign_x, sign_y);
			sign_y *= -1;
			ofs_y *= -1;
		}
		else if (a == 2) {
			swp = !swp;
			swap(ofs_x, ofs_y);
			swap(sign_x, sign_y);
			sign_x *= -1;
			ofs_x *= -1;
		}
		else if (a == 3) {
			sign_x *= -1;
			ofs_x *= -1;
			ofs_x += 2ll * b;
		}
		else {
			sign_y *= -1;
			ofs_y *= -1;
			ofs_y += 2ll*b;
		}
	};

	auto eval = [&](int p) -> pair<ll,ll> {
		auto [x, y] = XS[p];
		/*
		cerr << "x: " << x << " y: " << y << '\n';
		cerr << "ofx: " << ofs_x  << " ofy: " << ofs_y << '\n';
		cerr << "sx: " << sign_x << " sign_y: " << sign_y << '\n';
		cerr << "swp: " << swp << '\n';
		*/

		if (swp) swap(x, y);
		x = x * sign_x + ofs_x;
		y = y * sign_y + ofs_y;

		return {x, y};
	};

	vector<pair<ll,ll>> ans(Q);
	int op = 0;
	for (auto &[m, p, i] : QS) {
		while (op < M and op < m) {
			apply(op);
			op++;
		}

		ans[i] = eval(p);
	}

	for (auto [a, b] : ans) {
		cout << a << ' ' << b << '\n';
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	run();
}
