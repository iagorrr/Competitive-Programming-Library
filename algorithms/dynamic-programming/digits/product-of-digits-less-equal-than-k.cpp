using ll = long long;

map<int, int>	Q2({{2,1},{4,2}, {6,1}, {8,3}}),
       		Q3({{3,1}, {6,1}, {9, 2}}),
		Q5({{5,1}}),
		Q7({{7,1}});

const int MAXLEN = 19;
map<ll, map<ll, map<ll,map<ll,ll>>>> memo[MAXLEN][2][2][2];
map<int, map<int, map<int,map<int,bool>>>> done[MAXLEN][2][2][2];
string digts;
ll K;

ll _solve(int p, bool below, bool zero, bool any, int q2, int q3, int q5, int q7) {
	if (p == (int)digts.size()) {
		ll prod = 1;
		while(q2--) prod*=2ll;
		while(q3--) prod*=3ll;
		while(q5--) prod*=5ll;
		while(q7--) prod*=7ll;
		return zero or prod <= K;
	}

	if (done[p][below][any][zero][q2][q3][q5][q7])
		return memo[p][below][any][zero][q2][q3][q5][q7];

	ll ans = 0;
	int u = below ? 9 : digts[p]-'0';
	for (int i = 0; i <= u; i++) {
		ans += _solve(	p+1,
			       	below | (i<digts[p]-'0'),
			       	zero | (i==0 and any),
				any | (i>0),
				q2 + Q2[i],
				q3 + Q3[i],
				q5 + Q5[i],
				q7 + Q7[i]);
	}

	done[p][below][any][zero][q2][q3][q5][q7] = 1;
	return memo[p][below][any][zero][q2][q3][q5][q7] = ans;
}

ll solve() {
	return _solve(0, 0, 0, 0, 0, 0, 0, 0) - 1;
}
