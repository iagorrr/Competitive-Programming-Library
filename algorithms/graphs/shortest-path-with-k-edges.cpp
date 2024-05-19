template <typename T>
vector<vector<T>> prod(vector<vector<T>> &a, vector<vector<T>> &b) {
	const T _oo = numeric_limits<T>::max();
	int n = a.size();
	vector<vector<T>> c(n, vector<T>(n, _oo));
 
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				if (a[i][k] != _oo and b[k][j] != _oo)
					c[i][j] = min(c[i][j], a[i][k] + b[k][j]);
 
	return c;
}
 
template <typename T>
vector<vector<T>> shortest_with_k_moves(vector<vector<T>> adj, long long k) {
	if (k == 1) return adj;

	auto ans = adj;
	k--;
 
 
	while (k) {
		if (k & 1) ans = prod(ans, adj);
		k >>= 1;
		adj = prod(adj, adj);
	}

	return ans;
}
