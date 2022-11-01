// iagorrr ;)
#include <stdio.h>
#define lli long long int

lli solve(int n){
	lli ans = 0;
	while(n--){
		int x;
		scanf("%i", &x);
		ans += x;
	}
	return ans;
}

int main(){
	int n;
	scanf("%i", &n);
	printf("%lli\n", solve(n));
	return 0;
}

// AC.
