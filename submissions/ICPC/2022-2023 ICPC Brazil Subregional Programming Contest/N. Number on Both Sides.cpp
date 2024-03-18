#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN =  1'00'000;
int N, K, L;
pair<ll, ll> CARDS[MAXN];

ll ans;
ll sumFront, sumBack;
multiset<ll> back_used, back_unused;

void add(int p) {
	auto [front, back] = CARDS[p];
	sumFront += front;

	if ((int)back_used.size() < L) {
		sumBack += back;
		back_used.emplace(back);
	}
	else {
		auto lower_back_used = back_used.begin();
		if (*lower_back_used < back) {
			sumBack -= *lower_back_used;
			back_unused.emplace(*lower_back_used);
			back_used.erase(lower_back_used);

			sumBack += back;
			back_used.emplace(back);

		}
		else {
			back_unused.emplace(back);
		}
	}

}

void remove(int p) {
	auto [front, back] = CARDS[p];
	sumFront -= front;

	if (back_unused.find(back) != back_unused.end()) {
		back_unused.erase(back_unused.find(back));
	}
	else {
		sumBack -= back;
		back_used.erase(back_used.find(back));


		sumBack += *back_unused.rbegin();
		back_used.emplace(*back_unused.rbegin());
		back_unused.erase(back_unused.find(*back_unused.rbegin()));
	}
}

void dbg() {
	cerr << "sums : " << sumFront << ' ' << sumBack << '\n';

	cerr << "used: ";
	for (auto i : back_used) {
		cerr << i << ' ';
	}
	cerr << '\n';

	cerr << "unused: ";
	for (auto i : back_unused) {
		cerr << i << ' ';
	}
	cerr << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> CARDS[i].first;
	}

	for (int i = 0; i < N; i++) {
		cin >> CARDS[i].second;
	}

	cin >> K >> L;

	for (int i = 0; i < K; i++) {
		add(i);
	}

	ans = max(ans, sumFront + sumBack);
	// dbg();

	for (int p1 = K-1, p2 = N-1; p1 >= 0; p1--, p2--) {
		add(p2);
		// dbg();
		remove(p1);
		// dbg();
		ans = max(ans, sumFront + sumBack);
	}

	cout << ans << '\n';

}

// greddy, brute force
