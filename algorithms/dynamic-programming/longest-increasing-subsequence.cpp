template<typename T>
pair<int, vector<int>> lis(const vector<T> &xs) {
	int n = xs.size();

	vector<T> dp(n+1, numeric_limits<T>::max());
	dp[0] = numeric_limits<T>::min();

	int sz = 0;
	vector<int> psx(n);

	for (int i = 0; i < n; i++) {
		auto it = lower_bound(dp.begin(), dp.end(), xs[i]);
		auto pos = (int)(it - dp.begin());

		sz = max(sz, pos);

		dp[pos] = xs[i];

		psx[i] = pos;
	}

	return {sz, psx};
}

template<typename T>
vector<int> get_idx(vector<T> xs) {
	auto [sz1, psx1] = lis(xs);

	reverse(xs.begin(), xs.end());
	for (auto &xi : xs) xi = -xi;

	auto [sz2, psx2] = lis(xs);

	vector<int> ans;
	int _n = xs.size();
	for (int i = 0; i < _n; i++) {
		int l = psx1[i];
		int r = psx2[_n-i-1];
		if (l + r -1 == sz1) ans.push_back(i);
	}

	return ans;

}
