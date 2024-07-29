vector<vector<vector<int>>> DP;
void precomp(const string &S, const int MXK) {
	const int OO = 1'000'000'000;
	int N = S.size();
	DP = vector(N, vector(N, vector(MXK+1, OO)));
	for (int l = 0; l < N; l++) {
		for (int r = l; r < N; r++) {
			DP[l][r][0] = DP[l][r][1] = 0;
			if (l != r and MXK >= 2)
				DP[l][r][2] = S[l] != S[r];
		}
	}

	for (int sz = 3; sz <= N; sz++) {
		for (int l = 0; l + sz - 1 < N; l++) {
			int r = l + sz - 1;
			for (int k = 0; k <= MXK; k++) {
				DP[l][r][k] = min({
					DP[l][r][k],
					l +1 < N ? DP[l+1][r][k] : OO,
					r > 0  ? DP[l][r-1][k] : OO,
					k >= 2 and l+1 < N and r > 0 ? DP[l+1][r-1][k-2] + (S[l] != S[r]) : OO
				});
			}
		}
	}
}
