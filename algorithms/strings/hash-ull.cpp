using ull = unsigned long long;

const int MAXN(1'000'000);

const ull P = 31;
ull p[MAXN + 1];
void precompute() {
	p[0] = 1;
	for (int i = 1; i <= MAXN; i++)
	 p[i] = (P * p[i - 1]);
}

struct Hash {
	int n;
	vector<ull> h;
	// vector<ull> hi;
	Hash() {}

	Hash(const string& s) : n(s.size()), h(n) /*, hi(n) */ {
		h[0] = s[0];
		for (int i = 1; i < n; i++)
			h[i] = (s[i] + h[i - 1] * P);
		

		// hi[n - 1] = s[n - 1];
		// for (int i = n - 2; i >= 0; i--)
		// 	hi[i] = (s[i] + hi[i + 1] * P);
	}

	ull query(int l, int r) {
		ull hash = (h[r] - (l ? h[l - 1] * p[r - l + 1] : 0));
		return hash;
	}

	// ull query_inv(int l, int r) {
	// 	ull hash = (hi[l] - (r + 1 < n ? hi[r + 1] * p[r - l + 1] : 0));
	// 	return hash;
	// }
};

