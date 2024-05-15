#include <bits/stdc++.h>
using namespace std;

auto solve() {
	int N, J;
	cin>>N>>J;
	
	vector<int> hist(N);
	for(int i=0; i<N*J;i++) {
		int x; cin>>x;
		hist[i%N] += x;
	}
	int mx = 0;
	int ans = 0;
	for(int i=0; i<N; i++) {
		if(mx <= hist[i]) {
			mx = hist[i];
			ans = i+1;
		}
	}
	cout<<ans<<"\n";
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
}
