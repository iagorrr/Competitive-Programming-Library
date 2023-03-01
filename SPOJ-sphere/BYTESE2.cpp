// iagorrr ;)
// prefix sum delta sum
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
#define minpq  priority_queue<ll, vll, greater<ll>()>
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)
#define ll int
int32_t main(){ 
    fastio;
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;

		vector<int> psum(10000000+1, 0);
		int maxr = 0;
		while(n--){
			int l, r;
			cin >> l >> r;
			maxr = max({l, r, maxr});	
			psum[l]++;
			psum[r]--;
		}

		int ans = 0;
		for(int i = 1; i <= maxr; ++i){
			psum[i] += psum[i-1];
			ans = max(ans, psum[i]);
		}
		cout << ans << '\n';
	}

    return 0;
}
// AC.
