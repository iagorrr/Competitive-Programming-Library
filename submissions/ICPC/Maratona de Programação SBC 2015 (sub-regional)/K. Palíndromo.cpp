#include <bits/stdc++.h>
using namespace std;

string s;
vector<int> marked;
int n, m;

struct st {
	int sz, mcnt;
	st():sz(0), mcnt(0) {};

	bool operator <(const st b) const {
		return mcnt == b.mcnt ? sz < b.sz : mcnt < b.mcnt;
	}

	bool operator > (const st b) const {
		return mcnt == b.mcnt ? sz > b.sz : mcnt > b.mcnt;
	}
};

const int maxn = 2000;
vector<vector<st>> memo(maxn, vector<st>(maxn));
st solve(int l, int r) {
	if (l > r) {
		return st();
	}
	auto &[sz, mcnt] = memo[l][r];
	if (sz or mcnt) return memo[l][r];

	if (l == r) {
		sz = 1;
		mcnt = marked[l];
		return memo[l][r];
	}

	if (s[l] == s[r]) {
		sz = 2;
		mcnt =  marked[l] + marked[r];

		auto tmp = solve(l+1, r-1);
		memo[l][r] = max(memo[l][r], tmp);

		tmp.sz += 2;
		tmp.mcnt += marked[l] + marked[r];

		memo[l][r] = max(memo[l][r], tmp);
	}

	{
		auto tmp = solve(l+1, r);
		memo[l][r] = max(memo[l][r], tmp);

	}

	{
		auto tmp = solve(l, r-1);
		memo[l][r] = max(memo[l][r], tmp);
	}

	return memo[l][r];	
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	n = s.size();
	marked.resize(n);

	int m;
	cin >> m;
	
	for (int i = 0, p; i < m; i++) {
		cin >> p;
		p--;
		marked[p] = 1;
	}

	auto [ans, _] = solve(0, n-1);
	cout << ans << '\n';
}

// AC, dp, strings
