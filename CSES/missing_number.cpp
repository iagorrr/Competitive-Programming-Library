// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
#define minpq  priority_queue<ll, vll, greater<ll>()>
//•¨•.¸¸♪main•¨•.¸¸♪(　-ω-)ノ　(　・ω・)
int main(){ 
    fastio;
	ll n; cin >> n;

	vector<ll> a(n-1); for(auto &x : a) cin >> x;

	sort(a.begin(), a.end());
	ll ans(-1);
	for(int i = 1; i < n-1; ++i)
		if(a[i] - a[i-1] > 1) ans = a[i-1] + 1;


	if(ans == -1) ans = n;
	if(n == 2) ans = a[0] == 1 ? 2 : 1;

	cout << ans << '\n';
    return 0;
}
// AC.
