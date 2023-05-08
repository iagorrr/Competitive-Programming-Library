// iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int n; cin >> n;
	vector<int> a(n); for(auto &x : a) cin >> x;
	
	long long ans = 0;
	for(int i = 1; i < n; ++i)
	{
		ans += a[i] - a[i-1] >= 0 ? 0 : a[i-1] -a[i];
		a[i] = a[i] > a[i-1] ? a[i] : a[i-1];
	}
 
	cout << ans << '\n';
}
// AC.
