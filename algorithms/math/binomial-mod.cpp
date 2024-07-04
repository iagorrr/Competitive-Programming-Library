using ll = long long;
const int MOD = 998244353;
ll binom(ll n, ll k){
	const int BINMAX = 5'00'000;
	static ll FAC[BINMAX+1], FINV[BINMAX+1], INV[BINMAX+1];
	static bool done = false;
	if (!done) {
		FAC[0] = FAC[1] = INV[1] = FINV[0] = FINV[1] = 1;
		for(int i=2; i <= BINMAX; i++){
			FAC[i] = FAC[i-1]*i%MOD;
			INV[i] = MOD-MOD/i*INV[MOD%i]%MOD;
			FINV[i] = FINV[i-1]*INV[i]%MOD;
		}
		done = true;
	}

	if(n<k or n<0 or k<0) return 0;
	return FAC[n]*FINV[k]%MOD*FINV[n-k]%MOD;
}
