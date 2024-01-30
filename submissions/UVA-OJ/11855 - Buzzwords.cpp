#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll P = 31;
const ll MOD = 1e9 + 9;
const int MAXN(1e6);

ll ppow[MAXN+1];
void pre_calc() {
	ppow[0] = 1;
	for (int i = 1; i <= MAXN; i++)
		ppow[i] = (ppow[i-1] * P) % MOD;
}

struct Hash {
  int n;
  vll h, hi;
  Hash(const string &s) : n(s.size()), h(n), hi(n) {	  
    h[0] = s[0];
    hi[n-1] = s[n-1];
    for (int i = 1; i < n ; i++) {
      h[i] = (s[i] +  h[i - 1] * P) % MOD;
      hi[n-i-1] = (s[n-i-1] + hi[n - i - 1] * P) % MOD;
    }
  }

  ll qry(int l, int r) {
    ll hash =
      (h[r] - (l ? h[l - 1] * ppow[r - l + 1] % MOD : 0));
    return hash < 0 ? hash + MOD : hash;
  }

  ll qry_inv(int l, int r) {
    ll hash =
      (hi[l] -
       (r + 1 < n ? hi[r + 1] * ppow[r - l + 1] % MOD : 0));
    return hash < 0 ? hash + MOD : hash;
  }
};


string s;

void run() {
	string s2;
	for (auto c : s) if (c != ' ') s2.push_back(c);
	int n = (int)s2.size();
	Hash hs(s2);

	vector<ll> maxpersize(n+1);
	for (int sz = 1; sz < n; sz++) {
		map<ll,ll> mp;
		for (int j = 0; j  + sz - 1< n; j++) {
			ll hij = hs.qry(j, j+sz-1);
			mp[hij]++;
			maxpersize[sz] = max(maxpersize[sz],
					     mp[hij]);

			
		}
	}

	bool out = 0;
	for (int i = 1; i <= n; i++) {
		if (maxpersize[i] > 1)  {
			cout << maxpersize[i] << '\n';
			out = 1;
		}

	}

	if (out)
		cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	pre_calc();
	while(getline(cin, s)) {
		if (s.size() == 0) break;
		run();
	}
}

// AC, hashing
