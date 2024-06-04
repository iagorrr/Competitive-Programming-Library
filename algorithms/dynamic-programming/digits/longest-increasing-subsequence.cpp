int64_t memo[10+1][2][10+1][10];

int64_t solve(int p, bool low, bool nonzero, int last_digit, int need, const vector<int> &digits) {
	if (p < 0) return need == 0;
	if (need < 0) return 0;

	auto &ans = memo[p][nonzero][last_digit+1][need];
	if (low and ans != -1) return ans;

	int64_t ret = 0;
	int mx = low ? 9 : digits[p];

	for (int d = 0; d <= mx; d++) {
		if (d > last_digit and (d!=0 or (d==0 and nonzero)))
			ret += solve(p-1, low | (d < digits[p]), nonzero | (d!=0), d, need-1, digits);


		ret += solve(p-1, low | (d < digits[p]), nonzero | (d!=0), last_digit, need, digits);
	
	}

	return low ? ans = ret : ret;
}

vector<int> get_digits(int x) {
	vector<int> ret;
	for (;x;x/=10) ret.emplace_back(x%10);
	return ret;
}


pair<int, int64_t> solve(int x, int y) {
	// just need to call this once no matter how many queries
	memset(memo, -1, sizeof memo);
	vector<int64_t> lids(10);

	auto dy = get_digits(y);
	for (int sz = 1; sz < 10; sz++) {
		lids[sz] += solve(dy.size() - 1u, false, false, -1, sz, dy);
	}

	auto dx = get_digits(x-1);
	for (int sz = 1; sz < 10; sz++) {
		lids[sz] -= solve(dx.size() - 1u, false, false, -1, sz, dx);
	}

	for (int i = 9; i >= 1; i--) {
		if (lids[i]) {
			return {i, lids[i]};
		}
	}
	return {-1,-1};
}
