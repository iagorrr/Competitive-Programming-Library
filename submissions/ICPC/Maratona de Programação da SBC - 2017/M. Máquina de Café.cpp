#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll a,b,c;
	cin >>a>>b>>c;

	cout << min(2*b+4*c, min(2*b + 4*a, 2*a+2*c)) << "\n";	
}

// AC, math
