#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	vector<ll> as(n), bs(n);
	for (auto &ai : as) cin >> ai;
	for (auto &bi : bs) cin >> bi;

	const ll  p = 31;
	const ll mod = 1e9+9;
	vector<ll> ppow(n+1);
	ppow[0] = 1;
	for (int i = 1; i <= n; i++) {
		ppow[i] = (ppow[i-1] * p) % mod;
	}


	set<ll> st;
	vector<ll> ha2(n+1);
	map<ll, ll> id;
	int curid = 1;
	for (int i = 1; i <= n; i++) {
		int ai = as[i-1];
		ha2[i] = ha2[i-1];

		if (st.find(ai) == st.end()) {
			ha2[i] = (ha2[i] + ppow[curid]) % mod;
			id[ai] = curid++;
			st.emplace(ai);
		}

	}

	st.clear();
	vector<ll> hb2(n+1);
	for (int i = 1; i <= n; i++) {
		int bi = bs[i-1];
		hb[i] = hb[i-1];
		hb2[i] = hb2[i-1];

		if (st.find(bi) == st.end()) {
			st.emplace(bi);
			if (id[bi] == 0) 
				id[bi] = curid++;
			hb2[i] = (hb2[i] + ppow[id[bi]]) % mod;
		}
	}

	int q;
	cin >> q;
	while (q--) {
		int pa, pb;
		cin >> pa >> pb;
		cout << (ha2[pa] == hb2[pb] ? "Yes" : "No") << '\n';
	}
}

// AC, hashing
