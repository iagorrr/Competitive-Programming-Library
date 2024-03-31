#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxbit = 100;

int main() {
	ll a, b, c;
	cin >> a >> b >> c;
	
	bitset<maxbit> bb, aa;
	for (int i = 0; i < 60; i++) {
		if ((1ll<<i) & c) {
			if (a > b) {
				a--;
				aa[i] = 1;
			}
			else {
				b--;
				bb[i] = 1;
			}
		}
	}

	if (a < 0 or b < 0 or (a != b)) {
		cout << -1 << '\n';
		return 0;
	}

	for (int i = 0; i < 60 and a and b; i++) {
		if ((1ll<<i)&c) continue;
		a--, b--;
		aa[i] = 1, bb[i] = 1;
	}

	if (a or b) {
		cout << -1 << '\n';
		return 0;
	}

	cout << aa.to_ullong() << ' ' << bb.to_ullong() << '\n';;

}

/*
   	> dps que tu distribui os bits originais
	entre a e b, a quantidade de bits que eles
	precisam tem que ser igual, pq vai ter
	que por bits nos dois pra o xor não zuar.
		> alem disso tem que distribuir de modo que
		não passe dos 2^60
	- dar os bits gulosamente para aquele que
	precisa de mais (os obrigatórios no caso)

 */

// AC, bitwise operations
