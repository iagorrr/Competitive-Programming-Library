#include <bits/stdc++.h>

using namespace std;

int n;
int g[1000000];
int main() {
	cin >> n;

	vector<int> a, b;
	for (int i = 0; i < n; i++) {
		a.push_back(i);
	}

	int l = 0;
	int r= n/2;
	while(r < n) {
		b.push_back(a[r]);
		b.push_back(a[l]);
		l++;
		r++;
	}

	int pos = 0;
	int ans =1 ;
	pos = b[pos];
	while (pos != 0) {
		pos = b[pos];
		ans++;
	
	}
	cout << ans << endl;
  return 0;
}

/*
 * AC
 * Graphs
 * */
