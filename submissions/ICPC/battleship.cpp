#include<bits/stdc++.h>
using namespace std;

void solve(){
}
int main(){
	int n;
	cin >> n;

	vector<vector<int>> v(11, vector<int>(11, 0));
	while(n--){
		int d, l, r, c;
		cin >> d >> l >> r >> c;
		
		int prabaixo = d == 1;
		int lado = d == 0;
		
		int x = r, y = c;
		for(int i = 0; i < l; ++i) {
			if(x > 10 or y > 10) {
				cout << "N\n";
				exit(0);
			}
			v[x][y]++;
			if(v[x][y] >= 2) {
				cout << "N\n";
				exit(0);
			}
			x  += prabaixo;
			y  += lado;
		}
	}

	cout << "Y\n";
	return 0;
}

// AC, implementation
