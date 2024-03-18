#include <bits/stdc++.h>
using namespace std;

const int MAXL = 2 * 1'00'000;
int B, L;
int DS[MAXL];

int MOD;
int BPows[MAXL];
int N;
void precalc() {
	BPows[0] = 1;
	for (int i = 1; i < L; i++) {
		BPows[i] =
			(BPows[i-1] * B) % (MOD);
	}

	for (int i = 0; i < L; i++) {
		N = (N + ((BPows[L-i-1] * DS[i]) % MOD)) % MOD;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> B >> L;
	MOD = B + 1;
	for (int i = 0; i < L; i++) {
		cin >> DS[i];
	}

	precalc();

	if (N == 0) {
		cout << 0 << ' ' << 0 << '\n';
		return 0;
	}

	cerr << "N: " << N << '\n';
	for (int i = 0; i < L; i++) {
		if (!DS[i]) continue;
		// change 1 by 1
		if (!((L-i-1) & 1)) {
			if (DS[i] >= N) {
				int di = DS[i];
				di -= N;
				di = di % (MOD);
				cout << i + 1 << ' ' << di << '\n';
				return 0;
			}
		}
		else { // change B by B
			int diff = B - N;
			int di = DS[i];
			if (di >= (diff+1)) {
				di -= (diff+1);
				di = di % MOD;
				cout << i + 1 << ' ' << di << '\n';
				return 0;
			}
		}
	}


	cout << -1 << ' ' << -1 << '\n';

}

// AC, number theory
